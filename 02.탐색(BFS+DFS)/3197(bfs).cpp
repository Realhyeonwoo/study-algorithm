#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int R, C;
char map[1500][1500];
bool visited[1500][1500];
vector<pair<int, int> > swan;
queue<pair<int, int> > moveQ, moveNextQ, waterQ, waterNextQ;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool move_bfs() {
	while(!moveQ.empty()) {
		int y = moveQ.front().first;
		int x = moveQ.front().second;
		moveQ.pop();
		
		if(y == swan[1].first && x == swan[1].second) return true;
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(visited[ny][nx]) continue;
			
			if(map[ny][nx] == 'X') {
				visited[ny][nx] = true;
				moveNextQ.push(make_pair(ny, nx));
			} else {
				visited[ny][nx] = true;
				moveQ.push(make_pair(ny, nx));
			}
			
		}
	}
	return false;
}

void water_bfs() {
	while(!waterQ.empty()) {
		int y = waterQ.front().first;
		int x = waterQ.front().second;
		waterQ.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(map[ny][nx] == 'X') {
				map[ny][nx] = '.';
				waterNextQ.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			scanf(" %c", &map[y][x]);
			if(map[y][x] != 'X') waterQ.push(make_pair(y, x));
			if(map[y][x] == 'L') {
				swan.push_back(make_pair(y, x));
			}
		}
	}
	// SIMULATION
	moveQ.push(make_pair(swan[0].first, swan[0].second));
	visited[swan[0].first][swan[0].second] = true;
	
	int answer = 0;	
	while(1) {
		if(move_bfs()) break;
		water_bfs();
		
		moveQ = moveNextQ;
		waterQ = waterNextQ;
		
		while(!moveNextQ.empty()) moveNextQ.pop();
		while(!waterNextQ.empty()) waterNextQ.pop();
		answer++;
	}
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
