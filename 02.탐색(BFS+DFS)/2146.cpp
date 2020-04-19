#include<iostream>
#include<queue>
#include<cstring>

#define MAX 100
using namespace std;

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int answer = 987654321;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void makeIslandNum(int y, int x, int islandNum) {
	queue<pair<int, int> > q;	
	visited[y][x] = true;
	map[y][x] = islandNum;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
			if(visited[ny][nx] || map[ny][nx] != -1) continue;
			visited[ny][nx] = true;
			map[ny][nx] = islandNum;
			q.push(make_pair(ny, nx));
		}
	}
	
}

void bfs(int y, int x, int island) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	
	int count = 0;
	while(!q.empty()) {
		int qSize = q.size();
		for(int i=0; i<qSize; i++) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();
		
			for(int dir=0; dir<4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
			
				if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
				if(visited[ny][nx] || map[ny][nx] == island) continue;
				if(map[ny][nx] != 0 && map[ny][nx] != island) {
					answer = min(answer, count);
					return;
				}
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}	
		}
		if(q.size() != 0) count++;
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 1) map[y][x] = -1;
		}
	}
	
	// SIMULATION
	int islandNum = 0;
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == -1) {
				islandNum++;
				makeIslandNum(y, x, islandNum);			
			}
		}
	}
	
	for(int i=1; i<=islandNum; i++) {
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(map[y][x] == i) {
					memset(visited, false, sizeof(visited));
					bfs(y, x, i);
				}
			}
		}
	}
	
	//OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
