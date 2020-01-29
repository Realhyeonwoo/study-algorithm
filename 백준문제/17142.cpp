#include<iostream>
#include<utility>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
int map[50][50];
vector<int> answer; 

void simulation_bfs() {
	queue< pair<int, int> > q;
	int backup[n][n];
	bool visited[n][n];
	memset(visited, false, sizeof(visited));
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			backup[y][x] = map[y][x];
			if(backup[y][x] == -1) {
				q.push(make_pair(y, x));
			}
			if(backup[y][x] == 2) {
				backup[y][x] = -1;
			}
		}
	}
	
	int time = 0; 
	while(!q.empty()) {
		time++;
		
		queue< pair<int, int> > temp;
		while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			temp.push(make_pair(y, x));
			q.pop();
		}
		
		while(!temp.empty()) {
			pair<int, int> cur = temp.front();
			temp.pop();
		
			int cy = cur.first;
			int cx = cur.second;

			int dy[] = {-1, 1, 0, 0};
			int dx[] = {0, 0, -1, 1};
			for(int dir=0; dir<4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
			
				if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
				
				if(!visited[ny][nx] && backup[ny][nx] == 0) {
					visited[ny][nx] = true;
					backup[ny][nx] = time;
					q.push(make_pair(ny, nx));
				}
			}	
		}
	}	
		
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(backup[y][x] == 0) return;
		}
	}
	answer.push_back(time-1);
}

void virus_dfs(int count, int sy, int sx) {
	if(count == m){
		simulation_bfs();
		return; 	
	}
	for(int y=sy; y<n; y++) {
		for(int x=sx; x<n; x++) {
			if(map[y][x] == 2) {
				map[y][x] = -1;
				virus_dfs(count+1, y, x);
				map[y][x] = 2;
			}
		}
		sx = 0;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	for(int y=0; y<n; y++) {
		for(int x=0; x<n; x++) {
			if(map[y][x] == 1) map[y][x] = -2;
		}
	}
	virus_dfs(0, 0, 0);
	
	if(answer.size() != 0) {
		int min = *min_element(answer.begin(), answer.end());
		printf("%d\n", min);	
	} else {
		printf("%d", -1);
	}
	
	
	return 0;
}
