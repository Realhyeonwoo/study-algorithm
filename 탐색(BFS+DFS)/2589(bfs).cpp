#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int H, W;
char map[50][50];
bool visited[50][50];
int answer; 

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs(int y, int x) {
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
				
				if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
				if(visited[ny][nx] || map[ny][nx] == 'W') continue;
			
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
		if(q.size() != 0) count++;
	}
	
	return count;
}

int main(void) {
	// INPUT
	scanf("%d %d", &H, &W);
	for(int y=0; y<H; y++) {
		for(int x=0; x<W; x++) {
			scanf(" %c", &map[y][x]); 
		}
	}
	
	// SIMULATION
	for(int y=0; y<H; y++) {
		for(int x=0; x<W; x++) {
			if(map[y][x] == 'L') {
				int res = bfs(y, x);
				answer = max(res, answer);
				memset(visited, false, sizeof(visited));
			}
		}
	}
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
