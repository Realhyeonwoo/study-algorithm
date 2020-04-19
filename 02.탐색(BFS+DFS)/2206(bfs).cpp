#include<iostream>
#include<queue>
using namespace std;

int N, M;
int map[1001][1001];
bool visited[1001][1001][2];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int move_bfs(int y, int x) {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	visited[y][x][0] = true;
	q.push(make_pair(make_pair(y, x), make_pair(1 ,0)));
	
	while(!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cnt = q.front().second.first;
		int ability = q.front().second.second;
		q.pop();
		
		if(cy == N && cx == M) return cnt;
		
		if(ability < 1) {
			for(int dir=0; dir<4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				
				if(ny<1 || ny>N || nx<1 || nx>M) continue;
				if(visited[ny][nx][ability] || map[ny][nx] != 1) continue;
				visited[ny][nx][ability+1] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(cnt+1, ability+1)));
			}
		}
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
				
			if(ny<1 || ny>N || nx<1 || nx>M) continue;
			if(visited[ny][nx][ability] || map[ny][nx] != 0) continue;
			visited[ny][nx][ability] = true;
			q.push(make_pair(make_pair(ny, nx), make_pair(cnt+1, ability)));
		}
	}
	return -1;
}
int main(void) {
	//INPUT
	scanf("%d %d", &N, &M);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=M; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	// SIMULATION
	int answer = move_bfs(1, 1);
	
	// OUTPUT
	if(answer == -1) {
		printf("-1\n");
	} else {
		printf("%d\n", answer);
	}
	
	return 0;
}
