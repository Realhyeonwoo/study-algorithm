#include<iostream>
#include<utility>
#include<cstring>
#include<queue>
using namespace std;

int T;
int size;
int visited[300][300] = {0, };
int sy, sx;
int ty, tx;

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int cy = cur.first;
		int cx = cur.second;
		
		if(cy==ty && cx== tx) {
			break;
		}
		
		int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
		int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
		for(int dir=0; dir<8; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if(ny<0 || ny>=size || nx<0 || nx>=size) continue;
			if(visited[ny][nx] != 0) continue;
			
			visited[ny][nx] = visited[cy][cx] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		scanf("%d", &size);
		memset(visited, 0, sizeof(visited));
		scanf("%d %d", &sy, &sx);
		scanf("%d %d", &ty, &tx);
		
		bfs(sy, sx);
		
		printf("%d\n", visited[ty][tx]);
	}
	return 0;
}
