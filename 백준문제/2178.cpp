//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//int n, m;
//int map[101][101];
//int value[101][101];
//bool visited[101][101];
//struct Point {
//	int y, x;
//};
//
//void miro_bfs(int y, int x) {
//	memset(visited, false, sizeof(visited));
//	memset(value, 0, sizeof(value));
//	
//	Point point = {y, x};
//	
//	queue<Point> q;
//	q.push(point);
//	visited[y][x] = true;
//	value[y][x] = 1;
//	
//	while(!q.empty()) {
//		Point cur = q.front();
//		q.pop();
//		int cy = cur.y;
//		int cx = cur.x;
//		
//		
//		int dy[] =  {-1, 1, 0, 0};
//		int dx[] = {0, 0, -1, 1};
//		for(int dir=0; dir<4; dir++) {
//			int ny = cy + dy[dir];
//			int nx = cx + dx[dir];
//			
//			if(ny<1 || ny>n || nx<1 || nx>m) continue;
//			if(map[ny][nx] == 0) continue;
//			if(visited[ny][nx]) continue;
//			
//			
//			visited[ny][nx] = true;
//			value[ny][nx] = value[cy][cx] + 1;
//			
//			Point p = {ny, nx};
//			q.push(p);
//		}
//	}
//}
//
//int main(void) {
//	scanf("%d %d", &n, &m);
//	for(int y=1; y<=n; y++) {
//		for(int x=1; x<=m; x++) {
//			scanf("%1d", &map[y][x]);
//		}
//	}
//	
//	miro_bfs(1, 1); 
//	
//	printf("%d\n", value[n][m]);
//	return 0;
//}


#include<iostream>
#include<string>
#include<queue>
#define MAX 100
using namespace std;

int N, M;
int map[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> N >> M;
	string str;
	for(int y=0; y<N; y++) {
		cin >> str;
		for(int x=0; x<M; x++) {
			map[y][x] = str[x] - '0';
			if(map[y][x] == 1) map[y][x] = -1;
		}
	}
	
	// SIMULATION
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	map[0][0] = 1;
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(map[ny][nx] != -1) continue;
			q.push(make_pair(ny, nx));
			map[ny][nx] = map[y][x] + 1;
		}
	}
	
	// OUTPUT
	cout << map[N-1][M-1] << '\n';
	return 0;
}
