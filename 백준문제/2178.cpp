#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int map[101][101];
int value[101][101];
bool visited[101][101];
struct Point {
	int y, x;
};

void miro_bfs(int y, int x) {
	memset(visited, false, sizeof(visited));
	memset(value, 0, sizeof(value));
	
	Point point = {y, x};
	
	queue<Point> q;
	q.push(point);
	visited[y][x] = true;
	value[y][x] = 1;
	
	while(!q.empty()) {
		Point cur = q.front();
		q.pop();
		int cy = cur.y;
		int cx = cur.x;
		
		
		int dy[] =  {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<1 || ny>n || nx<1 || nx>m) continue;
			if(map[ny][nx] == 0) continue;
			if(visited[ny][nx]) continue;
			
			
			visited[ny][nx] = true;
			value[ny][nx] = value[cy][cx] + 1;
			
			Point p = {ny, nx};
			q.push(p);
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for(int y=1; y<=n; y++) {
		for(int x=1; x<=m; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	
	miro_bfs(1, 1); 
	
	printf("%d\n", value[n][m]);
	return 0;
}
