#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Point {
	int h, y, x;
};

int M, N, H;
int map[100][100][100];
bool visited[100][100][100];
queue<Point> q;
int count;

int dh[] = {0, 0, 0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};

void bfs() {
	while(!q.empty()) {
		int qSize = q.size();
		for(int i=0; i<qSize; i++) {
			int h = q.front().h;
			int y = q.front().y;
			int x = q.front().x;
			visited[h][y][x] = true;
			q.pop();
			
			for(int dir=0; dir<6; dir++) {
				int nh = h + dh[dir];
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(nh<0 || nh>=H || ny<0 || ny>=N || nx<0 || nx>=M) continue;
				if(visited[nh][ny][nx] || map[nh][ny][nx] != 0) continue;
				visited[nh][ny][nx] = true;
				map[nh][ny][nx] = 1;
				Point p = {nh, ny, nx};
				q.push(p);
			}
		}
		if(!q.empty()) count++;
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &M, &N, &H);
	for(int h=0; h<H; h++) {
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				scanf("%d", &map[h][y][x]);
				Point p = {h, y, x};
				if(map[h][y][x] == 1) q.push(p);
			}
		}
	}
	
	// SIMULATION
	bfs();
	
	// OUTPUT
	for(int h=0; h<H; h++) {
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				if(map[h][y][x] == 0) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
