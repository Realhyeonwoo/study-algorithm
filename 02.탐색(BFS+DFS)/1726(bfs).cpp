#include<iostream>
#include<queue>
using namespace std;

struct Point {
	int y, x, d;
};

Point sPoint, ePoint;
int M, N; // 세로(M), 가로(N)
int map[101][101];
bool visited[101][101][5]; // 동(1) 서(2) 남(3) 북(4)

int dy[] = {0, 0, 0, 1, -1};
int dx[] = {0, 1, -1, 0, 0};

int rotate(int d, char turn) {
	if(turn == 'L') {
		switch(d) {
			case 1: return 4;
			case 2: return 3;
			case 3: return 1;
			case 4: return 2;
		}
	}
	if(turn == 'R') {
		switch(d) {
			case 1: return 3;
			case 2: return 4;
			case 3: return 2;
			case 4: return 1;
		}
	}
}

bool canGo(int y, int x, int d, int v) {
	int ny = y + dy[d] * v;
	int nx = x + dx[d] * v;
	if(ny<1 || ny>M || nx<1 || nx>N) return false;
	
	ny = y;
	nx = x;
	for(int i=1; i<=v; i++) {
		ny += dy[d];
		nx += dx[d];
		if(map[ny][nx] == 1) return false;
	}
	
	return true;
}

int bfs(int y, int x, int d) {
	queue<pair<pair<int, int>, pair<int, int> > > q; // y, x, direction, cnt
	visited[y][x][d] = true;
	q.push(make_pair(make_pair(y, x), make_pair(d, 0)));
	
	while(!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int d = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		
		if(cy == ePoint.y && cx == ePoint.x && d == ePoint.d) return cnt;
		
		// 방향없이 직진
		for(int v=1; v<=3; v++)  {
			if(canGo(cy, cx, d, v)) {
				int ny = cy + dy[d] * v;
				int nx = cx + dx[d] * v;
				
				if(!visited[ny][nx][d]) {
					visited[ny][nx][d] = true;
					q.push(make_pair(make_pair(ny, nx), make_pair(d, cnt+1)));	
				}
			}	
		}
		
		
		// 방향 변경 
		int nd;
		// 왼쪽 회전
		nd = rotate(d, 'L');
		if(!visited[cy][cx][nd]) {
			visited[cy][cx][nd] = true;
			q.push(make_pair(make_pair(cy, cx), make_pair(nd, cnt+1)));
		}
		// 오른쪽 회전 
		nd = rotate(d, 'R');
		if(!visited[cy][cx][nd]) {
			visited[cy][cx][nd] = true;
			q.push(make_pair(make_pair(cy, cx), make_pair(nd, cnt+1)));
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &M, &N);
	for(int y=1; y<=M; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	int y, x, dir;
	scanf("%d %d %d", &y, &x, &dir);
	sPoint = {y, x, dir};
	scanf("%d %d %d", &y, &x, &dir);
	ePoint = {y, x, dir};
	
	// SIMULATION
	int answer = bfs(sPoint.y, sPoint.x, sPoint.d);
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
