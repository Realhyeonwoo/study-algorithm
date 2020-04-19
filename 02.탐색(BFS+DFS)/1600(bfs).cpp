#include<iostream>
#include<queue>
using namespace std;

int K, W, H;
int map[200][200];
bool visited[200][200][31];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int hy[] = {-2, -2, -1, -1, 2, 2, 1, 1};
int hx[] = {-1, 1, -2, 2, -1, 1, -2, 2};

int bfs(int y, int x, int a, int c) {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	visited[y][x][a] = true;
	q.push(make_pair(make_pair(y, x), make_pair(a, c))); 
	
	while(!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int ability = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		
		if(cy == H-1 && cx == W-1) return cnt; 
		
		if(ability < K) {
			for(int dir=0; dir<8; dir++) {
				int ny = cy + hy[dir];
				int nx = cx + hx[dir];
				
				if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
				if(visited[ny][nx][ability+1] || map[ny][nx] == 1) continue;
				
				visited[ny][nx][ability+1] = true;
				q.push(make_pair(make_pair(ny, nx), make_pair(ability+1, cnt+1)));
			}
		}
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
			if(visited[ny][nx][ability] || map[ny][nx] == 1) continue;
			
			visited[ny][nx][ability] = true;
			q.push(make_pair(make_pair(ny, nx), make_pair(ability, cnt+1)));
		}
	}
	
	return -1;
}

int main(void) {
	// INPUT
	scanf("%d", &K);
	scanf("%d %d", &W, &H);
	for(int y=0; y<H; y++) {
		for(int x=0; x<W; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// SIMULATION
	int answer = bfs(0, 0, 0, 0);
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
