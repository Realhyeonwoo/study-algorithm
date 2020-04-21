#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 13
using namespace std;

typedef struct {
	int num, y, x, dir;
}Pos;

int N, K;
int map[MAX][MAX]; // 1 ~ 12 
vector<Pos> malInfo[MAX][MAX]; // 1 ~ 12
vector<Pos> v;
bool isEnd = false;
int dy[] = {0, 0, 0, -1, 1};
int dx[] = {0, 1, -1, 0, 0};

bool isOver(void) {
	for(int i=1; i<v.size(); i++) {
		int temp = malInfo[v[i].y][v[i].x].size();
		if(malInfo[v[i].y][v[i].x].size() >= 4) return true;
	}
	return false;
}

int getStartIdx(int num, int y, int x) {
	for(int i=0; i<malInfo[y][x].size(); i++) {
		if(malInfo[y][x][i].num == num) return i;
	}
}
void moveToWhite(int num, int y, int x, int ny, int nx) {
	int startIdx = getStartIdx(num, y, x);
	for(int i=startIdx; i<malInfo[y][x].size(); i++) {
		malInfo[ny][nx].push_back({malInfo[y][x][i].num, ny, nx, malInfo[y][x][i].dir});
		v[malInfo[y][x][i].num].y = ny;
		v[malInfo[y][x][i].num].x = nx;
	}
	malInfo[y][x].erase(malInfo[y][x].begin()+startIdx, malInfo[y][x].begin()+malInfo[y][x].size());
}

void moveToRed(int num, int y, int x, int ny, int nx) {
	int startIdx = getStartIdx(num, y, x);
	for(int i=malInfo[y][x].size()-1; i>=startIdx; i--) {
		malInfo[ny][nx].push_back({malInfo[y][x][i].num, ny, nx, malInfo[y][x][i].dir});
		v[malInfo[y][x][i].num].y = ny;
		v[malInfo[y][x][i].num].x = nx;
	}
	malInfo[y][x].erase(malInfo[y][x].begin()+startIdx, malInfo[y][x].begin()+malInfo[y][x].size());
}

int inverseDir(int d) {
	if(d == 1) return 2;
	else if(d == 2) return 1;
	else if(d == 3) return 4;
	else if(d == 4) return 3;
}

void move(void) {
	for(int i=1; i<v.size(); i++) {
//		printf("==============[%d]=================\n", i);
		int y = v[i].y;
		int x = v[i].x;
		int dir = v[i].dir;
		
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<1 || ny>N || nx<1 || nx>N) { // 범위 벗어날 때 
			int nd = inverseDir(dir);
			v[i].dir = nd;
			int startIdx = getStartIdx(i, y, x);
			malInfo[y][x][startIdx].dir = nd;
			
			ny = y + dy[nd];
			nx = x + dx[nd];
			
			if(ny<1 || ny>N || nx<1 || nx>N) {
			} else if(map[ny][nx] == 0) {
				moveToWhite(i, y, x, ny, nx); 	
			} else if(map[ny][nx] == 1) {
				moveToRed(i, y, x, ny, nx);	
			}
		} else if(map[ny][nx] == 0) { // 흰색 일때 
			moveToWhite(i, y, x, ny, nx); 
		} else if(map[ny][nx] == 1) { // 빨간색 
			moveToRed(i, y, x, ny, nx);
		} else if(map[ny][nx] = 2) { // 파란색 
			int nd = inverseDir(dir);
			v[i].dir = nd;
			int startIdx = getStartIdx(i, y, x);
			malInfo[y][x][startIdx].dir = nd;
			ny = y + dy[nd];
			nx = x + dx[nd];
			if(ny<1 || ny>N || nx<1 || nx>N) {
			} else if(map[ny][nx] == 0) {
				moveToWhite(i, y, x, ny, nx); 	
			} else if(map[ny][nx] == 1) {
				moveToRed(i, y, x, ny, nx);	
			}
		}
		if(isOver()) {
			isEnd = true;
			return;
		}
		
//		for(int y=1; y<=N; y++) {
//			for(int x=1; x<=N; x++) {
//				if(malInfo[y][x].size() != 0) {
//					for(int i=0; i<malInfo[y][x].size(); i++) {
//						printf("[%d] ", malInfo[y][x][i].num);
//						printf("%d ", malInfo[y][x][i].y);
//						printf("%d ", malInfo[y][x][i].x);
//						printf("%d ", malInfo[y][x][i].dir);
//						printf("\n");
//					}
//				}
//			}
//		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &K);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	v.push_back({0, 0, 0, 0});
	int a, b, c;
	for(int i=1; i<=K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({i, a, b, c});
		malInfo[a][b].push_back({i, a, b, c});
	}
	
	// SIMULAION
	int answer = 1; 
	while(1) {
		if(answer > 1000) {
			answer = -1;
			break;
		}
//		printf("====================== %d =======================\n", answer);
		move();
		if(isEnd) break;
		answer++;
	}
	
	printf("%d\n", answer);
	return 0; 
}
