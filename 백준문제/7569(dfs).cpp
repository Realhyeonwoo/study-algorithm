#include<iostream>
#include<cstring>
using namespace std;

int m, n, h;
int map[100][100][100];
int visited[100][100][100] = {false, };
int day = 0; 

void dfs(int i, int y, int x) {
		
	int dy[] = { -1, 1, 0, 0, 0, 0};
	int dx[] = { 0, 0, -1, 1, 0, 0};
	int dz[] = { 0, 0, 0, 0, 1, -1};
	for(int dir=0; dir<6; dir++) {
		int nh = i + dz[dir];
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(nh<0 || nh>=h || ny<0 || ny>=n || nx<0 || nx>=m) continue;
		if(map[nh][ny][nx] == 1) continue;
		map[nh][ny][nx] = 1;
		dfs(nh, ny, nx);
	}
}

int main(void){
	scanf("%d %d %d", &m, &n, &h);
	for(int i=0; i<h; i++) {
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++) {
				scanf("%d", &map[i][y][x]);
			}
		}
	}
	
	for(int i=0; i<h; i++) {
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++) {
				if(!visited[i][y][x] &&map[i][y][x] == 1) {
					dfs(i, y, x);	
				}
			}
		}
	}
	printf("\n\n");
	for(int i=0; i<h; i++) {
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++) {
				printf("%d ", map[i][y][x]);
			}
			printf("\n");
		}
	}
	printf("%d\n", day);
	return 0; 
}
