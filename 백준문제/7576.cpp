#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int m, n;
int map[1000][1000] = {0, };
int visited[1000][1000] = {0, };
bool flag = false;

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		int cy = cur.first;
		int cx = cur.second;
		
		map[cy][cx] = 1;
		
		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny= cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
			if(map[ny][nx] == 0) {
				visited[ny][nx] = visited[cy][cx] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &m, &n); // m: ����(x), n: ����(y)
	for(int y=0; y<n; y++)  {
		for(int x=0; x<m; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 0) flag = true;
		}
	}
	
	//  ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ���
	if(!flag) {
		printf("0\n");
		return 0; 
	}
	
	// Ž�� 
	for(int y=0; y<n; y++)  {
		for(int x=0; x<m; x++) {
			if(map[y][x] == 1) {
				bfs(y, x);
			}
		}
	}
	
	// �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ���
	for(int y=0; y<n; y++)  {
		for(int x=0; x<m; x++) {
			if(map[y][x] == 0) {
				printf("-1\n");
				return 0; 
			}
		}
	}
	
	
			printf("\n");
	for(int y=0; y<n; y++)  {
		for(int x=0; x<m; x++) {
			printf("%d ", visited[y][x]);
		}
		printf("\n");
	}
			printf("\n");
			
			
	int day = 0;
	for(int y=0; y<n; y++)  {
		for(int x=0; x<m; x++) {
			if(day < visited[y][x]) {
				day = visited[y][x];
			}
		}
	}
	
	printf("%d\n", day);
	return 0;
}
