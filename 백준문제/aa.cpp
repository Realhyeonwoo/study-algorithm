#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int N; // ������ ũ��
int map[20][20];
int sy, sx; // ����� ��ġ
int size = 2; // ����� ũ�� 
// ����� ����

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
		// �Ʊ�� �ƹ��ŵ� ���� �� �� ������ Ż��  
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

		// ����� Ž��
		bool eat = false;
		int min = 99999; // ���� �������� �Ÿ�  
		int fy = 0, fx = 0; // ���� ����� ��ǥ   
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				// ��� �ΰ��� ���� 
				if(map[y][x] == 9) continue;
				if(map[y][x] == 0 || map[y][x] >= size) continue;
				
				// Ȯ���� ���� �����ġ �� �� ����
				memset(copyMap, -1, sizeof(copyMap));
				int fish_y = y, fish_x = x;
				for(int i=0; i<N; i++) {
					for(int j=0; j<N; j++) {
						copyMap[i][j] = map[i][j];
					}
				}	
				// �ش� ����� ���� �� �� �ִ��� Ȯ��
				memset(visited, false, sizeof(visited));
//				printf("####[%d %d]####\n", fish_y, fish_x);
				int dis = goToFish(fish_y, fish_x, sy, sx, 0);
//				printf("dis: %d\n", dis);
				// �� �� ������ �̵��Ÿ�(==�ɸ��ð�) ��ȯ 
				if(dis != 0 && min > dis) {
					eat = true;
					min = dis;				
					fy = y;
					fx = x;			
				}	
			}
		}
		
		if(eat) {
			// ��ǥ ������ �̵� �� �Ա�
			count += min; // �̵� �ð� ��� 
			map[sy][sx] = 0;
			sy = fy; sx = fx; // ��� ��ǥ �̵� 
			map[sy][sx] = 0;
			eatFish += 1; // ���� ����� �� Ȯ��
			// size �� ���� ����� �� �� 
			if(size == eatFish)  {
				size++;
				eatFish = 0;
			}
		}
	}

	printf("%d\n", count);
	
	return 0;
}
