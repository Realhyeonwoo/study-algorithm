#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int n;
int map[100][100];
int copyMap[100][100];
bool visited[100][100] = {false, };

void bfs(int y, int x, int color) {
//	printf("color: %d\n", color);
	queue< pair<int, int> > q;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int cx = cur.first;
		int cy = cur.second;
		
		visited[cy][cx] = true;
		copyMap[cy][cx] = 0;
		
//		printf("\n\n");
//		for(int y=0; y<n; y++) {
//			for(int x=0; x<n; x++) {
//				printf("%d ", copyMap[y][x]);
//			}
//			printf("\n");
//		}	
//		printf("\n\n");
		
		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
//			printf("%d \n", copyMap[ny][nx]);
			if(copyMap[ny][nx] != color || visited[ny][nx])continue;
//			printf("q¿¡Ãß°¡: [%d, %d]\n", ny, nx);
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	scanf("%d", &n);
	char temp;
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			scanf("%1s", &temp);
			if(temp == 'R') {
				map[y][x] = 1;
			} else if(temp == 'G') {
				map[y][x] = 2;
			} else {
				map[y][x] = 3;
			}
		}
	}
	// R:1, G:2, B:3	
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			copyMap[y][x] = map[y][x];
		}
	}
	
	int count = 0; 
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(copyMap[y][x] != 0) {
				count++;
				bfs(y, x, copyMap[y][x]);
			}
		}
	}	
	
	printf("%d\n", count);
	return 0; 
}
