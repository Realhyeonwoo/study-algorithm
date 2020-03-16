#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Point {
	int h, y, x;
};

int L, R, C; // 높이(L), 행(R), 열(C)
char building[31][31][31]; // 1 ~ 30
bool visited[31][31][31]; // 1 ~ 30
int value[31][31][31];

Point start, endPoint;

int dh[] = {0, 0, 0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};

int move_bfs(void) {
	queue<Point> q;
	q.push(start);
	
	while(!q.empty()) {
		Point cur = q.front();
		q.pop();
		int h = cur.h; int y = cur.y; int x = cur.x;
		visited[h][y][x] = true;
		
//		if(h == endPoint.h && y == endPoint.y && x == endPoint.x) return value[h][y][x];

		for(int dir=0; dir<6; dir++) {
			int nh = h + dh[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(nh<1 || nh>L || ny<1 || ny>R || nx<1 || nx>C) continue;
			if(building[nh][ny][nx] == '#' || visited[nh][ny][nx]) continue;		
			
			visited[nh][ny][nx] = true;
			value[nh][ny][nx] = value[h][y][x] + 1;
		
			if(nh == endPoint.h && ny == endPoint.y && nx == endPoint.x) return value[nh][ny][nx];
					
			q.push({nh, ny, nx});
		}
	}
	return -1;
}

int main(void) {
	while(1) {
		// RESET
		memset(visited, false, sizeof(visited));
		memset(value, 0, sizeof(value));
		
		// INPUT
		scanf("%d %d %d", &L, &R, &C); 
		if(L==0 && R==0 && C==0) break;
		for(int h=1; h<=L; h++) {
			for(int y=1; y<=R; y++) {
				for(int x=1; x<=C; x++) {
					scanf(" %c", &building[h][y][x]);
					if(building[h][y][x] == 'S') start = {h, y, x};
					if(building[h][y][x] == 'E') endPoint = {h, y, x};
				}
			}
		}
	
		// SIMULATION 
		int answer = move_bfs();
	
		// OUTPUT	
		if(answer == -1) {
			printf("Trapped!\n");
		} else {
			printf("Escaped in %d minute(s).\n", answer);
		}
	}
		
	return 0;
}
