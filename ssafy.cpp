#include<iostream>
#include<queue>
#include<cstring>

#define MAX 10
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int answer = 0;

int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int dir=0; dir<8; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=10 || nx<0 || nx>=10) continue;
			if(visited[ny][nx] || map[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		answer = 0;
		memset(visited, false, sizeof(visited));
		
		// INPUT
		for(int y=0; y<MAX; y++) {
			for(int x=0; x<MAX; x++) {
				scanf("%d", &map[y][x]);
			}
		}
		
		// SIMULATION
		for(int y=0; y<MAX; y++) {
			for(int x=0; x<MAX; x++) {
				if(map[y][x] == 1 && !visited[y][x]) {
					bfs(y, x);
					answer++;
				}
			}
		}
		
		// OUTPUT	
		printf("#%d %d\n", tc, answer);
	}
	return 0;
}
