#include<iostream>
using namespace std;

int N;
int map[100][100];
int answer = -1;

int floodMap[100][100];
void flood(int rain) {
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] <= rain) {
				floodMap[y][x] = 0;
				continue;
			}
			floodMap[y][x] = map[y][x];
		}
	}
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void checkIsland_dfs(int y, int x) {
	floodMap[y][x] = 0; 
	
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
		if(floodMap[ny][nx] == 0) continue;
		
		checkIsland_dfs(ny, nx);
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N); 
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	// SIMULATION
	for(int rain=1; rain<=100; rain++) {
		flood(rain); 
		
		int count = 0; 
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(floodMap[y][x] == 0) continue;
				checkIsland_dfs(y, x);
				count++;
			}
		}
		if(count > answer) answer = count;
	}
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
