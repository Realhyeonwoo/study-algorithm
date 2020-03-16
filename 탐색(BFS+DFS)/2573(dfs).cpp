#include<iostream>
#include<cstring>
using namespace std;

int N, M; // За(N), ї­(M)
int map[300][300];
int copyMap[300][300];
bool visited[300][300];
int answer;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void checkSeperate_dfs(int y, int x) {
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
		if(visited[ny][nx]) continue;
		if(map[ny][nx] == 0) continue;
		
		visited[ny][nx] = true;
		checkSeperate_dfs(ny, nx);
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	bool isSeperate = false;
	int count;
	while(1) {
		// RESET
		memset(copyMap, 0, sizeof(copyMap));
		memset(visited, false, sizeof(visited));
		count = 0; 
		
		// CHECK_SEPERATE
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				if(map[y][x] == 0 || visited[y][x]) continue;
				count++;
				visited[y][x] = true;
				checkSeperate_dfs(y, x);
			}
		}
		if(count >= 2) break;
	
		// MELT	
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				copyMap[y][x] = map[y][x];
			}
		}
		
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {		
				if(map[y][x] == 0) continue;
				int sea = 0; 
				for(int dir=0; dir<4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if(copyMap[ny][nx] == 0) sea++;
				}
				map[y][x] -= sea;
				if(map[y][x] < 0) map[y][x] = 0;
			}	
		}
		
		// CHECK_allMELTED
		bool isMeltedAll = true;
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				if(map[y][x] != 0) {
					isMeltedAll = false;
				}
			}
		}
		if(isMeltedAll) {
			answer = 0;
			break;
		} else {
			answer++;	
		}
	}
	
	// OUTPUT
	printf("%d", answer);
	
	return 0; 
}
