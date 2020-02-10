#include<iostream>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;

int n, m, answer;
int map[8][8];

void virus_bfs(void) {
	queue< pair<int, int> > q;
	int backup[8][8]; 
	bool visited[8][8];
	memset(visited, false, sizeof(visited));
	for(int y=0; y<n; y++) {
		for(int x=0; x<m; x++) {
			backup[y][x] = map[y][x];
			if(backup[y][x] == 2) {
				q.push(make_pair(y, x));
			}
		}
	}
	
	while(!q.empty()) {
		pair<int, int> cur = q.front(); 
		q.pop(); 
		
		int cy = cur.first;
		int cx = cur.second;
		
		backup[cy][cx] = 2;
		
		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
			if(!visited[ny][nx] && backup[ny][nx] == 0) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
	
	int res = 0; 
	for(int y=0; y<n; y++) {
		for(int x=0; x<m; x++) {
			if(backup[y][x] == 0) res++; 
		}
	}
	if(answer < res) answer = res; 
}

void wall_dfs(int count, int sy, int sx) {
	if(count == 3) {
		virus_bfs(); 
		return; 
	}
	for(int y=sy; y<n; y++) {
		for(int x=sx; x<m; x++) {
			if(map[y][x] == 0) {
				map[y][x] = 1;
				wall_dfs(count+1, y, x); 
				map[y][x] = 0;
			}
		}
		sx = 0; 
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for(int y=0; y<n; y++) {
		for(int x=0; x<m; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	wall_dfs(0, 0, 0); 
	
	printf("%d\n", answer);
	return 0; 
}
