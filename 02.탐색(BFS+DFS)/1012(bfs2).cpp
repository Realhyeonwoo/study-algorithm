#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int T, M, N, K; // 가로(M), 세로(N), 배추입력 
int map[50][50];
bool visited[50][50];
int answer; 

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int y, int x) {
	queue<pair<int, int> > q;	
	visited[y][x] = true;
	map[y][x] = 0;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(visited[ny][nx] || map[ny][nx] == 0) continue;
			visited[ny][nx] = true;
			map[ny][nx] = 0;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		answer = 0; 
		
		// INPUT
		scanf("%d %d %d", &M, &N, &K);
		for(int i=0; i<K; i++) {
			int y, x;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		
		// SIMULATION
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				if(map[y][x] == 1) {
					answer++;
					bfs(y, x);
				}
			}
		}
		// OUTPUT
		printf("%d\n", answer); 
	}
	return 0;
}
