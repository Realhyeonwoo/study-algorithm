#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Point {
	int l, y, x;
};

int L, R, C;
char map[31][31][31];
bool visited[31][31][31];
Point sPoint, ePoint;

int dh[] = {0, 0, 0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};

int move(Point p) {
	queue<pair<Point, int> > q;
	visited[p.l][p.y][p.x] = true;
	q.push(make_pair(p, 0));
	
	while(!q.empty()) {
		int l = q.front().first.l;
		int y = q.front().first.y;
		int x = q.front().first.x;
		int cnt = q.front().second;
		q.pop();

		if(l == ePoint.l && y == ePoint.y && x == ePoint.x) return cnt;
		
		for(int dir=0; dir<6; dir++) {
			int nl = l + dh[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(nl<1 || nl>L || ny<1 || ny>R || nx<1 || nx>C) continue;
			if(visited[nl][ny][nx] || map[nl][ny][nx] == '#') continue;
			
			visited[nl][ny][nx] = true;
			Point temp = {nl, ny, nx};
			q.push(make_pair(temp, cnt + 1));
		}
	}
	
	return -1;
}

int main(void) {
	while(1) {
		// RESET
		memset(visited, false, sizeof(visited));
		
		// INPUT
		scanf("%d %d %d", &L, &R, &C);
		if(L==0 && R==0 && C==0) break;
		for(int l=1; l<=L; l++) {
			for(int y=1; y<=R; y++) {
				for(int x=1; x<=C; x++) {
					scanf(" %c", &map[l][y][x]);
					if(map[l][y][x] == 'S') {
						sPoint.l = l;
						sPoint.y = y;
						sPoint.x = x;
					}
					if(map[l][y][x] == 'E') {
						ePoint.l = l;
						ePoint.y = y;
						ePoint.x = x;
					}
				}
			}
		}
		
		// SIMULATION
		int answer = move(sPoint);
		
		// OUTPUT
		if(answer == -1) {
			printf("Trapped!\n");
		} else {
			printf("Escaped in %d minute(s).\n", answer);
		}
	}
	return 0;
}
