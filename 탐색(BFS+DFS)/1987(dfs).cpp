#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int R, C;
char map[20][20];
bool visited[20][20];
int value[20][20];
vector<char> passed;
int answer = -987654321;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void check_dfs(int y, int x, int cnt) {
	answer = max(answer, cnt);
	
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
		if(visited[ny][nx]) continue;
		bool flag = false;
		for(int i=0; i<passed.size(); i++) {
			if(passed[i] == map[ny][nx]) {
				flag = true;
				break;
			}
		}
		if(flag) continue;
		
		visited[ny][nx] = true;
		passed.push_back(map[ny][nx]);
		check_dfs(ny, nx, cnt+1);
		visited[ny][nx] = false;
		passed.pop_back();
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C);
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	
	// SIMULATION
	passed.push_back(map[0][0]);
	check_dfs(0, 0, 1);
	
	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
