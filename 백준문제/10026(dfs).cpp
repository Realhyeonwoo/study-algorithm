#include<iostream>
#include<cstring>
using namespace std;

int n;
int map[100][100];
int backup[100][100];
bool visited[100][100] = {false, };

void copyMap(void) {
	for(int y=0; y<n; y++)	 {
		for(int x=0; x<n; x++) {
			backup[y][x] = map[y][x];
		}
	}
}

void copyMap2(void) {
	for(int y=0; y<n; y++)	 {
		for(int x=0; x<n; x++) {
			if(map[y][x] == 3) {
				backup[y][x] = map[y][x];	
			} else {
				backup[y][x] = 1;
			}
		}
	}
}

void dfs(int y, int x, int color) {
	visited[y][x] = true;
	backup[y][x] = 0;
	
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
		if(visited[ny][nx] || backup[ny][nx] != color) continue;
		dfs(ny, nx, color); 
	}
}
int main(void) {
	scanf("%d", &n);
	char temp;
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			scanf("%1s", &temp);
			switch(temp) {
			case 'R':
				map[y][x] = 1;
				break;
			case 'G':
				map[y][x] = 2;
				break;
			case 'B':
				map[y][x] = 3;
				break;
			}
		}
	}
	
	copyMap();
	
	int count = 0;
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(backup[y][x] != 0) {
				count++;
				dfs(y, x, backup[y][x]);
			}
		}
	}
	
	copyMap2();
	memset(visited, false, sizeof(visited));
	
	int count2 = 0;
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(backup[y][x] != 0) {
				count2++;
				dfs(y, x, backup[y][x]);
			}
		}
	}
	
	printf("%d %d \n", count, count2);
	return 0;
}
