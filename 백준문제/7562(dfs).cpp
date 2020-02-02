#include<iostream>
#include<cstring>
using namespace std;

int T;
int size;
int sy, sx, ty, tx;
bool visited[300][300] = {false, };
int count;
int minV = 999999;

void dfs(int y, int x, int cnt) {
	printf("[%d, %d](cnt: %d) \n", y, x, cnt);
	if(y==ty && x==tx && (minV > cnt)) {
		minV = cnt;
		count = cnt;
		printf("[%d, %d](cnt: %d) \n", y, x, cnt);
		return;
	}
	
	visited[y][x] = true;
	
	int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
	for(int dir=0; dir<8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=size || nx<0 || nx>=size) continue;
		if(visited[ny][nx]) continue;
		
		dfs(ny, nx, cnt+1);
		
	}
		
}
int main(void) {
	scanf("%d", &T);
	
	for(int test_case=1; test_case<=T; test_case++) {
		scanf("%d", &size);
		scanf("%d %d", &sy, &sx);
		scanf("%d %d", &ty, &tx);
		
		memset(visited, false, sizeof(visited));
		count = 0; 
		minV = 999999;
		dfs(sy, sy, 0);
		
		printf("%d\n", count);
	}
	return 0;
}
