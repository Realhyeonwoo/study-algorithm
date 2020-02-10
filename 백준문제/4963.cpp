#include<iostream>
#include<cstring>
using namespace std;

int w, h; // w:너비(x),  h:높이(y) 
int map[50][50];
bool visited[50][50] = {false, };

void dfs(int y, int x) {
	visited[y][x] = true;
	
	int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
	int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
	for(int dir=0; dir<8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
		if(visited[ny][nx] || map[ny][nx]==0) continue;
		dfs(ny, nx);
	}
}

int main(void) {
	while(true) {
		scanf("%d %d", &w, &h);	
		if(w==0 && h==0) break;
		
		for(int y=0; y<h; y++) {
			for(int x=0; x<w; x++) {
				scanf("%d", &map[y][x]);			
			}
		}	
		
		memset(visited, false, sizeof(visited));
		int count = 0;
		for(int y=0; y<h; y++) {
			for(int x=0; x<w; x++) {
				if(!visited[y][x] && map[y][x] == 1) {					
					count++;
					dfs(y, x);
				}
			}
		}
		printf("%d\n", count);
	}
	
	return 0;
}
