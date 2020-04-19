#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

char map[12][6];
bool visited[12][6];
vector<pair<int, int> > v, temp_v;
int answer;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void check_dfs(int y, int x) {
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=12 || nx<0 || nx>=6) continue;
		if(map[ny][nx] != map[y][x]) continue;
		if(map[ny][nx] == '.') continue;
		if(visited[ny][nx]) continue;
		
		visited[ny][nx] = true;
		temp_v.push_back(make_pair(ny, nx));
		check_dfs(ny, nx);
	}
}

int main(void) {
	// INPUT
	for(int y=0; y<12; y++)	 {
		for(int x=0; x<6; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	
	// SIMULATION
	while(1) {
		// RESET
		bool isDestroy = false;
		memset(visited, false, sizeof(visited));
		
		// CHECK_BLOCK(DFS)
		for(int y=0; y<12; y++) {
			for(int x=0; x<6; x++) {
				if(map[y][x] != '.' && visited[y][x]) continue;
				
				visited[y][x] = true;
				temp_v.push_back(make_pair(y, x));
				check_dfs(y, x);
				
				if(temp_v.size() >= 4) {
					isDestroy = true;
					for(int i=0; i<temp_v.size(); i++) {
						v.push_back(temp_v[i]);
					}
				}
				
				temp_v.clear();
			}
		}
		
		// DESTROY_BLOCK
		for(int i=0; i<v.size(); i++) {
			int y = v[i].first;
			int x = v[i].second;
			map[y][x] = '.';
		}
		
		// MOVE_BLOCK
		for(int y=10; y>=0; y--) {
			for(int x=0; x<6; x++) {
				if(map[y][x] == '.') continue;
				int tmp = y;
				while(1) {
					if(tmp == 11 || map[y+1][x] != '.') break;
					map[tmp+1][x] = map[tmp][x];
					map[tmp][x] = '.';
					tmp++;
				}
			}
		}
			
		// IS_DESTROY
		if(!isDestroy) break;
		answer++;
	}
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
