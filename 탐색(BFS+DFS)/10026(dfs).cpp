#include<iostream>
#include<cstring>
using namespace std;

int N;
int map[100][100];
int copyMap[100][100];
int answer1, answer2;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void check_dfs(int check, int color, int y, int x) {
	if(check == 0) {
		map[y][x] = 0;	
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
		
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(map[ny][nx] != color) continue;
			check_dfs(check, color, ny, nx);
		}
	} else {
		copyMap[y][x] = 0;
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
		
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(copyMap[ny][nx] != color) continue;
			check_dfs(check, color, ny, nx);
		}
	}
	
	
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	char temp;
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf(" %c", &temp);
			switch(temp) {
				case 'R': // 1
					map[y][x] = 1;
					copyMap[y][x] = 1;
					break;
				case 'G': // 2
					map[y][x] = 2;
					copyMap[y][x] = 1;
					break;				
				case 'B': //3 
					map[y][x] = 3;
					copyMap[y][x] = 3;
					break;
			}
		}
	}
	
	// SIMULATION
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] != 0) {
				answer1++;
				check_dfs(0, map[y][x], y, x);
			}
			if(copyMap[y][x] != 0) {
				answer2++;
				check_dfs(1, copyMap[y][x], y, x);
			}
		}
	}
	
	// OUTPUT
	printf("%d %d\n", answer1, answer2);
	
	return 0;
}
