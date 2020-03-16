#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int R, C;
char map[50][50];
bool visited[50][50];
int value[50][50];

int water_y, water_x;
int hedgehog_y, hedgehog_x;
int water[50][50];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<pair<int, int> > waterQ;
void makeWatermap_bfs() {
	int num = 0;
	while(!waterQ.empty()) {
		int qSize = waterQ.size(); 
		
		num++;
		for(int i=0; i<qSize; i++) {
			int cy = waterQ.front().first;
			int cx = waterQ.front().second;
			visited[cy][cx] = true;
			waterQ.pop(); 
			
			for(int dir=0; dir<4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
			
				if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
				if(visited[ny][nx]) continue;
				if(map[ny][nx] == 'D' || map[ny][nx] =='X') continue;
			
				visited[ny][nx] = true;
				water[ny][nx] = num;
				waterQ.push(make_pair(ny, nx));
			}
		}
	}
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			if(water[y][x] == 0) {
				water[y][x] = 987654321;	
			}
		}
	}
}

int move_bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
//		if(map[cy][cx] == 'D') {
//			return value[cy][cx];
//		}

		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(map[ny][nx] == 'D') {
				return value[cy][cx]+1;
			}
				
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(visited[ny][nx] || map[ny][nx] =='X' || map[ny][nx] == '*') continue;
			if(value[cy][cx]+1 >= water[ny][nx]) continue;
			visited[ny][nx] = true;
			value[ny][nx] = value[cy][cx] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	
	return -1;
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			scanf(" %c", &map[y][x]);
			if(map[y][x] == '*') {
				waterQ.push(make_pair(y, x));
			}
			if(map[y][x] == 'S') {
				hedgehog_y = y;
				hedgehog_x = x;
			}
		}
	}
	
	// SIMULATION
	makeWatermap_bfs();
	memset(visited, false, sizeof(visited));
	int answer = move_bfs(hedgehog_y, hedgehog_x);
	
	// OUTPUT
	if(answer == -1) {
		printf("KAKTUS\n");
	} else {
		printf("%d\n", answer);	
	}
}
