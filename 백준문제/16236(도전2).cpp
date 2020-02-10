	#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;

int N; // map size
int map[20][20];
bool visited[20][20];
int value[20][20];
int shark_size = 2; // 아기상어 크기 

void findFish(int shark_y, int shark_x) {
	memset(visited, false, sizeof(visited));
	memset(value, 0, sizeof(value));
	
	queue<pair<int, int> > q;
	q.push(make_pair(shark_y, shark_x));
	visited[shark_y][shark_x] = true;
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int cy = cur.first;
		int cx = cur.second;
		
		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(visited[ny][nx]) continue;
			if(value[ny][nx] != 0) continue;
			if(map[ny][nx] > shark_size) continue;
			
			value[ny][nx] = value[cy][cx] + 1;	
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	// 입력 
	scanf("%d", &N);
	int shark_y, shark_x; // 아기상어 위치  
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 9) {
				shark_y = y;
				shark_x = x;
			}
		}
	}
	
	// 시뮬레이션
	int time = 0;
	int count = 0; 
	while(true) {
		// 먹을 수 있는 물고기까지의 거리를 구함(vlaue 배열에 이동거리 저장) 
		findFish(shark_y, shark_x);
		
		// 상좌부터해서 이동거리가 가장 짧은 물고기의 좌표를 구함(fish_y, fish_x 에 저장) 
		int fish_y, fish_x;
		int minDis = 9999;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				// 물고기의 크기가 상어보다 작으며 && 물고기가 존재해야하며 &&  이동거리값이 0이 아니며 && minDis 보다 작으면  
				if(map[y][x]<shark_size && map[y][x]!=0 && value[y][x]!=0 && minDis>value[y][x]) {
					minDis = value[y][x];
					fish_y = y; fish_x = x;
				}
			}
		}
		
		// 물고기가 없다면 종료 
		if(minDis == 9999) break;
 
		// 물고기 먹기
		map[fish_y][fish_x] = 9;
		map[shark_y][shark_x] = 0;
		shark_y = fish_y; shark_x = fish_x;
		count++;
		if(count == shark_size) {
			count = 0;
			shark_size++;
		}
		time += minDis;
	}
	 
	// 정답 출력 
	printf("%d\n", time);
	
	return 0;
}
