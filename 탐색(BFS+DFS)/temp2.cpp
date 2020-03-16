#include<iostream>
#include<queue>

#define INF 987654321
#define MAX 100
using namespace std;

typedef struct {
	int y, x, dir;
}Pos;

int W, H;
char map[MAX][MAX];
int visited[MAX][MAX][4];
pair<int, int> Start, End;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

pair<int, int> changeDirection(int dir) {
	pair<int, int> nd;
	if(dir==0 || dir==1) {
		nd.first = 2;
		nd.second = 3;
	} else {
		nd.first = 0;
		nd.second = 1;
	}
	return nd;
}

void bfs() {
	queue<Pos> q;
	for(int dir=0; dir<4; dir++) {
		Pos temp = {Start.first, Start.second, dir};
		q.push(temp);
		visited[Start.first][Start.second][dir] = 0; 
	}
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();
		
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		pair<int, int> nd = changeDirection(dir);
		
		if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
		if(map[ny][nx] == '*') continue;
		if(map[ny][nx] == 'C') {
			if(visited[ny][nx][dir] > visited[y][x][dir]) {
				visited[ny][nx][dir] = visited[y][x][dir];
			}
		} else if(map[ny][nx] == '.') {
			if(visited[ny][nx][dir] > visited[y][x][dir]) {
				visited[ny][nx][dir] = visited[y][x][dir];
				Pos temp = {ny, nx , dir};
				q.push(temp);
			}
			if(visited[ny][nx][nd.first] > visited[y][x][dir]+1) {
				visited[ny][nx][nd.first] = visited[y][x][dir]+1;
				Pos temp = {ny, nx, nd.first};
				q.push(temp);
			}
			if(visited[ny][nx][nd.second] > visited[y][x][dir]+1) {
				visited[ny][nx][nd.second] = visited[y][x][dir]+1;
				Pos temp = {ny, nx, nd.second};
				q.push(temp);
			}
		}
	}
}
int main(void) {
	// INPUT
	scanf("%d %d", &W, &H);
	int tmp = 0;
	for(int y=0; y<H; y++) {
		for(int x=0; x<W; x++) {
			scanf(" %c", &map[y][x]);
			if(map[y][x] == 'C') {
				if(tmp == 0) {
					Start.first = y;
					Start.second = x;
					tmp++;
				} else {
					End.first = y;
					End.second = x;
				}
			}
			for(int dir=0; dir<4; dir++) {
				visited[y][x][dir] = INF;
			}
		}
	}
	
	// SIMULATION
	bfs(); 
	
	// OUTPUT
	int answer = INF;
	for(int dir=0; dir<4; dir++) {
		answer = min(answer, visited[End.first][End.second][dir]);
	}
	printf("%d\n", answer);
	
	return 0;
}
