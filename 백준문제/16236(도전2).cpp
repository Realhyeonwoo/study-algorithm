	#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;

int N; // map size
int map[20][20];
bool visited[20][20];
int value[20][20];
int shark_size = 2; // �Ʊ��� ũ�� 

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
	// �Է� 
	scanf("%d", &N);
	int shark_y, shark_x; // �Ʊ��� ��ġ  
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 9) {
				shark_y = y;
				shark_x = x;
			}
		}
	}
	
	// �ùķ��̼�
	int time = 0;
	int count = 0; 
	while(true) {
		// ���� �� �ִ� ���������� �Ÿ��� ����(vlaue �迭�� �̵��Ÿ� ����) 
		findFish(shark_y, shark_x);
		
		// ���º����ؼ� �̵��Ÿ��� ���� ª�� ������� ��ǥ�� ����(fish_y, fish_x �� ����) 
		int fish_y, fish_x;
		int minDis = 9999;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				// ������� ũ�Ⱑ ���� ������ && ����Ⱑ �����ؾ��ϸ� &&  �̵��Ÿ����� 0�� �ƴϸ� && minDis ���� ������  
				if(map[y][x]<shark_size && map[y][x]!=0 && value[y][x]!=0 && minDis>value[y][x]) {
					minDis = value[y][x];
					fish_y = y; fish_x = x;
				}
			}
		}
		
		// ����Ⱑ ���ٸ� ���� 
		if(minDis == 9999) break;
 
		// ����� �Ա�
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
	 
	// ���� ��� 
	printf("%d\n", time);
	
	return 0;
}
