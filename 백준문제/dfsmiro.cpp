#include<iostream>
using namespace std;

int map[8][8] = {  		{0,0,1,1,1,1,1,1},
						{1,0,0,0,0,0,0,1},
						{1,1,1,0,1,1,1,1},
						{1,1,1,0,1,1,1,1},
						{1,0,0,0,0,0,0,1},
						{1,0,1,0,1,1,1,1},
						{1,0,0,0,0,0,0,0},
						{1,1,1,1,1,1,1,5}
			};
bool v[8][8] = { false, };

int cnt = 1;

void dfs(int y, int x) {
	if(map[y][x] == 5) {
		printf("arrived: %d \n", cnt);
		return;
	}
	
	int dx[] = { -1, 1, 0, 0};
	int dy[] = { 0, 0, -1, 1};
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=8 || nx<0 || nx>=8) continue;
		if(v[ny][nx] || map[ny][nx]==1) continue;
		
		cnt += 1;
		v[ny][nx] = true;
		
		dfs(ny, nx);
		cnt -= 1;
		v[ny][nx] = false;
		
	}
}

int main(void) {
	dfs(0, 0); 
	
//	for(int y=0; y<8; y++) {
//		for(int x=0; x<8; x++) {
//			printf("%d ", map[y][x]);
//		}
//		printf("\n");
//	}
	return 0;
}
