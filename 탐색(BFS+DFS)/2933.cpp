#include<iostream>
#include<cstring>
using namespace std;

int R, C, N;
char map[101][101]; // 1 ~ 100
char copyMap[101][101];
bool visited[101][101];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void check_dfs(int y, int x) {
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
		if(copyMap[ny][nx] != 5 || visited[ny][nx]) continue;
		
		visited[ny][nx] = true;
		copyMap[ny][nx] = 1;
		check_dfs(ny, nx);
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	
	// SIMULATION
	scanf("%d", &N);
	int height;
	int direction = 1; // from ¿ÞÂÊ(1), ¿À¸¥ÂÊ(-1) 
	for(int n=1; n<=N; n++) {
		scanf("%d", &height); // R - height
		height = R - height;
		
		// CHECK_STICK DIRECTION && DESTROY_MINERAL
		bool isDestroy = false;
		if(direction == 1){
			for(int x=0; x<R; x++) {
				if(map[height][x] == 'x') {
					map[height][x] = '.';
					isDestroy = true;
					break;
				}
			}
		} else {
			for(int x=R-1; x>=0; x--) {
				if(map[height][x] == 'x') {
					map[height][x] = '.';
					isDestroy = true;
					break;
				}
			}
		}
		
		// CHECK_CLUSTER
		if(isDestroy) {
			memset(copyMap, 0, sizeof(copyMap));
			memset(visited, 0, sizeof(visited));
			
			for(int y=0; y<R; y++) {
				for(int x=0; x<C; x++) {
					if(map[y][x] == 'x') {
						copyMap[y][x] = 5;
					} else {
						copyMap[y][x] = 0;
					}
				}
			}
			
			for(int x=0; x<C; x++) {
				if(copyMap[R-1][x] != 5) continue;
				visited[R-1][x] = true;
				copyMap[R-1][x] = 1;
				check_dfs(R-1, x);
			}
			
			// MOVE_CLUSTER	
			for(int y=R-2; y>=0; y--) {
				for(int x=0; x<C; x++) {
					if(copyMap[y][x] != 5) continue;
					int tempY = y;
					while(1) {
						if(tempY == R-1 || map[tempY+1][x] == 'x') break;
						map[tempY+1][x] = 'x';
						map[tempY][x] = '.';
						copyMap[tempY+1][x] = 5;
						copyMap[tempY][x] = 0;
						tempY++;
					}
				}
			}
		}
		
		// CHANGE_DIRECTION
		direction *= -1;
	}
	
	
	
	// OUTPUT
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			printf("%c", map[y][x]);
		}
		printf("\n");
	}
	
	return 0;
}

/*

8 ........
7 ........
6 .....xx.
5 ...xxx..
4 ..xxx...
3 ..x.xxx.
2 ..x...x.
1 .xxx..x.


8 ........
7 ........
6 .....x..
5 ...xxx..
4 ..xxx...
3 ..x.xxx.
2 ..x...x.
1 .xxx..x.


8 ........
7 ........
6 .....x..
5 ...xxx..
4 ..xxx...
3 ..x.xxx.
2 ..x...x.
1 .xxx..x.


8 ........
7 ........
6 .....x..
5 ...xxx..
4 ...xx...
3 ..x.xxx.
2 ..x...x.
1 .xxx..x.



8 ........
7 ........
6 .....x..
5 ...xxx..
4 ...xx...
3 ..x.xx..
2 ..x...x.
1 .xxx..x.

8 ........
7 ........
6 .....x..
5 ...xxx..
4 ...xx...
3 ..x.xx..
2 ..x...x.
1 .xxx..x.


8 ........
7 ........
6 ........
5 ........
4 .....x..
3 ..xxxx..
2 ..xxx.x.
1 .xxxxxx.









8 ........
7 ........
6 ...x.xx.
5 ...xxx..
4 ..xxx...
3 ..x.xxx.
2 ..x...x.
1 .xxx..x.





*/
