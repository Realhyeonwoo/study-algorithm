#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int R, C;
int map[MAX][MAX];
int visited[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int getCheeseCount(void) {
	int sum = 0;
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			if(map[y][x] == 1) sum++;
		}
	}
	return sum;
}

void setInitMap(int a, int b) {
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	map[a][b] = -1;
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(map[ny][nx] == 0) {
				map[ny][nx] = -1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// SIMULAITON
	setInitMap(0, 0);
	
	queue<pair<int, int> > q;
	int time = 0, count = 0;
	while(1) {
		time++;
		count = getCheeseCount();
		
		for(int y=0; y<R; y++) {
			for(int x=0; x<C; x++) {
				if(map[y][x] == -1) q.push(make_pair(y, x));
			}
		}
		
		while(!q.empt)
		
	}
	
//	for(int y=0; y<R; y++) {
//		for(int x=0; x<C; x++) {
//			printf("%d ", map[y][x]);
//		}
//		printf("\n");
//	}
	
	// OUTPUT
	
	return 0;
}
