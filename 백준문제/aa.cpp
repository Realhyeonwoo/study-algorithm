#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int N; // 공간의 크기
int map[20][20];
int sy, sx; // 상어의 위치
int size = 2; // 상어의 크기 
// 복사용 변수

int copyMap[20][20]; 
bool visited[20][20];
int moveCount[20][20];

int goToFish(int fish_y, int fish_x, int cy, int cx, int cnt)  { 
	memset(moveCount, 0, sizeof(moveCount));
	queue<pair<int, int> > q;
	q.push(make_pair(cy, cx));
	
	visited[cy][cx] = true;
	

	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();	
		
		int shark_y = cur.first;
		int shark_x = cur.second;
		
		if(shark_y == fish_y && shark_x == fish_x) {
			break;
			
		}	
		
		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = shark_y + dy[dir];
			int nx = shark_x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(copyMap[ny][nx] > size) continue;
			if(visited[ny][nx]) continue;
			
			visited[ny][nx] = true;
			moveCount[ny][nx] = moveCount[shark_y][shark_x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	
	return moveCount[fish_y][fish_x];
}

int main(void) {
	memset(map, -1, sizeof(map));
	scanf("%d", &N);
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 9) {
				sy = y;
				sx = x; 				
			}
		}
	}
	
	int count = 0;
	int eatFish = 0;
	while(true)  {
		// 아기상어가 아무거도 이제 할 수 없을때 탈출  
		bool flag = true;
		for(int y=0; y<N; y++) {
			bool flag2 = false;
			for(int x=0; x<N; x++) {
				if(map[y][x] == 9) continue;
				if(map[y][x] != 0 && map[y][x] < size ) {
					flag = false;
					flag2 = true;
					break;
				}
			}
			if(flag2) break;
		}
		if(flag) {
			break;	
		} 

		// 물고기 탐색
		bool eat = false;
		int min = 99999; // 먹을 물고기와의 거리  
		int fy = 0, fx = 0; // 먹을 물고기 좌표   
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				// 상어 인곳은 무시 
				if(map[y][x] == 9) continue;
				if(map[y][x] == 0 || map[y][x] >= size) continue;
				
				// 확인을 위한 상어위치 및 맵 복사
				memset(copyMap, -1, sizeof(copyMap));
				int fish_y = y, fish_x = x;
				for(int i=0; i<N; i++) {
					for(int j=0; j<N; j++) {
						copyMap[i][j] = map[i][j];
					}
				}	
				// 해당 물고기 까지 갈 수 있는지 확인
				memset(visited, false, sizeof(visited));
//				printf("####[%d %d]####\n", fish_y, fish_x);
				int dis = goToFish(fish_y, fish_x, sy, sx, 0);
//				printf("dis: %d\n", dis);
				// 갈 수 있으면 이동거리(==걸린시간) 반환 
				if(dis != 0 && min > dis) {
					eat = true;
					min = dis;				
					fy = y;
					fx = x;			
				}	
			}
		}
		
		if(eat) {
			// 목표 물고기로 이동 및 먹기
			count += min; // 이동 시간 계산 
			map[sy][sx] = 0;
			sy = fy; sx = fx; // 상어 좌표 이동 
			map[sy][sx] = 0;
			eatFish += 1; // 먹은 물고기 수 확인
			// size 랑 먹은 물고기 수 비교 
			if(size == eatFish)  {
				size++;
				eatFish = 0;
			}
		}
	}

	printf("%d\n", count);
	
	return 0;
}
