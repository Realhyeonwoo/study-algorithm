#include<iostream>
#include<queue>
#include<cstring>
#include<utility>
using namespace std;

int t, m, n, k;
int map[50][50];
bool visited[50][50] = {false, };

void bfs(int y, int x) {
	queue< pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	
	while(!q.empty()) {
		pair<int, int> cur = q.front(); 
		q.pop(); 
		
		int cy = 
		int cx = 
		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
		
			if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
			if(map[ny][nx] != 0) {
				dfs(ny, nx);
			}
		}
	}
}

int main(void) {
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		memset(map, 0, sizeof(map));
		int cnt = 0;
		
		scanf("%d %d %d", &m, &n, &k);
		for(int i=0; i<k; i++) {
			int y, x;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
	
		for(int y=0; y<n; y++) {
			for(int x=0; x<m; x++) {
				if(map[y][x] == 1) {
					cnt++;
					bfs(y, x);
				}
			}
		}
		
		printf("%d\n", cnt);
	}
	return 0;
}
