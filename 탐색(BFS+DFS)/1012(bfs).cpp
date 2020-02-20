#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int T;
int M, N, K; // 가로(M), 세로(N), 지렁이수(K)
int map[50][50];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void check_bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x)); 
	map[y][x] = 0; 
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int cy = cur.first;
		int cx = cur.second;
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir]; 
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(map[ny][nx] == 0) continue;
			map[ny][nx] = 0;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void)  {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		memset(map, 0, sizeof(map));
		int count = 0;
		
		// INPUT
		scanf("%d %d %d", &M, &N, &K);
		for(int i=0; i<K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		
		// CHECK_BFS
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				if(map[y][x] == 1) {
					count++;
					check_bfs(y, x);
				}
			}
		}
		
		// OUTPUT
		printf("%d\n", count);
	}
	return 0;
}
