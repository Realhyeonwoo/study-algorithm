#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int R, C; // За(R), ї­(C)
char map[250][250];
bool visited[250][250];
int sheep, wolf;
int answerS, answerW;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop(); 
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(visited[ny][nx] || map[ny][nx] == '#') continue;
			
			if(map[ny][nx] == 'v') wolf++;
			if(map[ny][nx] == 'o') sheep++;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=0; y<R; y++) {
		for(int x =0; x<C; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	
	// SIMULATION
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			if(!visited[y][x] && map[y][x] != '#') {
				sheep = 0; wolf = 0;
				if(map[y][x] == 'v') wolf++;
				if(map[y][x] == 'o') sheep++;
				bfs(y, x);
				if(wolf < sheep) {
					answerS += sheep;
				} else {
					answerW += wolf;
				}
			}
		}
	}
	
	// OUTPUT
	printf("%d %d\n", answerS, answerW);
	return 0;
}
