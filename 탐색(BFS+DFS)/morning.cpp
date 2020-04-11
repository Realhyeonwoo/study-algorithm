#include<iostream>
#include<cmath>

#define MAX 10
#define INF 987654321
using namespace std;

int N, M, answer = INF;
char map[MAX][MAX];
pair<int, int> Red, Blue;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int inverseDirection(int d) {
	if(d == 0) return 1;
	else if(d == 1) return 0;
	else if(d == 2) return 3;
	else if(d == 3) return 2;
}

int calcDist(int ny, int nx, int y, int x) {
	return abs(ny - y) + abs(nx - x);
}

void move(int ry, int rx, int by, int bx, int cnt, int dir) {
	if(cnt > 10 || cnt >= answer) return;
	bool rFlag = false, bFlag = false;
	
	int nry = ry + dy[dir];
	int nrx = rx + dx[dir];
	while(1) {
		if(map[nry][nrx] == '#') break;
		if(map[nry][nrx] == 'O') {
			rFlag = true;
			break;	
		}
		nry += dy[dir];
		nrx += dx[dir];
	}
	nry -= dy[dir];
	nrx -= dx[dir];
	
	int nby = by + dy[dir];
	int nbx = bx + dx[dir];
	while(1) {
		if(map[nby][nbx] == '#') break;
		if(map[nby][nbx] == 'O') {
			bFlag = true;
			break;
		}
		nby += dy[dir];
		nbx += dx[dir];
	}
	nby -= dy[dir];
	nbx -= dx[dir];
	
	if(bFlag) return;
	if(rFlag) {
		answer = min(answer, cnt);
		return;
	}
	
	if(nry == nby && nrx == nbx) {
		int rDist = calcDist(nry, nrx, ry, rx);
		int bDist = calcDist(nby, nbx, by, bx);
		
		if(rDist > bDist) {
			nry -= dy[dir];
			nrx -= dx[dir];
		} else {
			nby -= dy[dir];
			nbx -= dx[dir];
		}
	}
	
	for(int i=0; i<4; i++) {
		if(i == dir) continue;
		if(i == inverseDirection(dir)) continue;
		move(nry, nrx, nby, nbx, cnt+1, i);
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf(" %c", &map[y][x]);
			if(map[y][x] == 'R') {
				Red.first = y;
				Red.second = x;
				map[y][x] = '.';
			}
			if(map[y][x] == 'B') {
				Blue.first = y;
				Blue.second = x;
				map[y][x] = '.';
			}
		}
	}
	
	// SIMULATION
	for(int dir=0; dir<4; dir++) {
		move(Red.first, Red.second, Blue.first, Blue.second, 1, dir);
	}
	
	// OUTPUT	
	if(answer > 10 || answer == INF) answer = -1;
	printf("%d\n", answer);
	
	return 0;
}
