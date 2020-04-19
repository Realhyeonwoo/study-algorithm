#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Point {
	int y, x;
};

int T;
int N, M; // За(N) ї­(M) 
char map[50][50];
int devilMap[50][50];
bool visited[50][50];
Point sPoint, ePoint;
queue<pair<int, int> > devil;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void spreadDevil() {
	int count = 1;
	while(!devil.empty()) {
		int qSize = devil.size();
		for(int i=0; i<qSize; i++) {
			int y = devil.front().first;
			int x = devil.front().second;
			devil.pop();
			
			for(int dir=0; dir<4; dir++){
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
				if(map[ny][nx] == 'X' || devilMap[ny][nx]>=0) continue;
				if(map[ny][nx] == 'D') continue;
				devilMap[ny][nx] = count;
				devil.push(make_pair(ny, nx));
			}			
		}
		if(devil.size() != 0) count++;
	}
}

int bfs(int y, int x) {
	queue<pair<pair<int, int>, int> > q; 
	visited[y][x] = true;
	q.push(make_pair(make_pair(y, x), 0));
	
	while(!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(cy == ePoint.y && cx == ePoint.x) return cnt; 
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(visited[ny][nx] || map[ny][nx] == 'X') continue;
			if(devilMap[ny][nx]>=0 && devilMap[ny][nx] <= cnt + 1) continue;
			visited[ny][nx] = true;
			q.push(make_pair(make_pair(ny, nx), cnt+1));
		}
	}
	return -1;
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		memset(devilMap, -1, sizeof(devilMap));
		memset(visited, false, sizeof(visited));
		
		// INPUT
		scanf("%d %d", &N, &M);
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				scanf(" %c", &map[y][x]);
				if(map[y][x] == 'S') {
					sPoint = {y, x};
				}
				if(map[y][x] == 'D'){
					ePoint = {y, x};
				}
				if(map[y][x] == '*') {
					devil.push(make_pair(y, x));
					devilMap[y][x] = 0;
				}
			}
		}
		
		// SIMULATION
		spreadDevil();
		int answer = bfs(sPoint.y, sPoint.x);
		
		// OUTPUT
		if(answer == -1) {
			 printf("#%d GAME OVER\n", test_case);
		} else {
			printf("#%d %d\n", test_case, answer);	
		}
		
	}
	return 0;
}
