#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;

int N, M;
int map[8][8];
int copyMap[8][8];
vector<pair<int, int> > emptyCoord;
bool visited[64];
int answer = -9875664321;
int test = 0; 

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void setTreeWall_dfs(int start, int wallCnt) {
	if(wallCnt == 3) {
		queue<pair<int, int> > q;
		// COPY MAP
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				copyMap[y][x] = map[y][x];
				if(copyMap[y][x] == 2) {
					q.push(make_pair(y, x));
				}
			}
		}		
		for(int i=0; i<emptyCoord.size(); i++) {
			if(visited[i] == true ) {
				int wall_y = emptyCoord[i].first;
				int wall_x = emptyCoord[i].second;
				copyMap[wall_y][wall_x] = 1;
			}
		}
		// SPREAD VIRUS		
		while(!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			int cy = cur.first;
			int cx = cur.second;
			
			for(int dir=0; dir<4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				
				if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
				if(copyMap[ny][nx] != 0) continue;
				copyMap[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
		// COUNT SAFE AREA(0)
		int count = 0;
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				if(copyMap[y][x] == 0) count++;
			}
		}
		if(answer < count) answer = count;
		
		return;
	}
	
	for(int i=start; i<emptyCoord.size(); i++) {
		if(visited[i]) continue;
		visited[i] = true;
		setTreeWall_dfs(i, wallCnt+1);
		visited[i] = false;	
	}
}

int main(void) {
	// INPUT	
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 0) {
				emptyCoord.push_back(make_pair(y, x));
			}
		}
	}
	
	// SIMULATION
	setTreeWall_dfs(0, 0);	
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
