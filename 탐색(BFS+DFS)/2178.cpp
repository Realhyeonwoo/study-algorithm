#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int map[101][101];
int value[101][101];
bool visited[101][101];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs() {
	queue<pair<int, int> > q;
	visited[1][1] = true;
	value[1][1] = 1;
	q.push(make_pair(1, 1));

	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<1 || ny>N || nx<1 || nx>M) continue;
			if(visited[ny][nx] || map[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			value[ny][nx] = value[cy][cx] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=M; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	bfs();
	
	printf("%d\n", value[N][M]);
	return 0;
}

// DFS 시간초과............. 
//#include<iostream>
//using namespace std;
//
//int N, M;
//int map[101][101];
//bool visited[101][101];
//int answer = 987654321;
//
//int dy[] = {-1, 1, 0, 0};
//int dx[] = {0, 0, -1, 1};
//
//void dfs(int y, int x, int cnt) {
//	if(y == N && x == M) {
//		answer = min(answer, cnt);
//		return;
//	}
//	
//	for(int dir=0; dir<4; dir++) {
//		int ny = y + dy[dir];
//		int nx = x + dx[dir];
//		
//		if(ny<1 || ny>N || nx<1 || nx>M) continue;
//		if(visited[ny][nx] || map[ny][nx] == 0) continue;
//		visited[ny][nx] = true;
//		dfs(ny, nx, cnt + 1);
//		visited[ny][nx] = false;
//	}
//}
//
//int main(void) {
//	scanf("%d %d", &N, &M);
//	for(int y=1; y<=N; y++) {
//		for(int x=1; x<=M; x++) {
//			scanf("%1d", &map[y][x]);
//		}
//	}
//	
//	visited[1][1] = true;
//	dfs(1, 1, 1);
//
//	printf("%d\n", answer);
//	
//	return 0;
//}
