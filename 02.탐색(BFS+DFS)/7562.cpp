#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T, l;
int map[300][300];
bool visited[300][300];
int value[300][300];

int dy[] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int start_y, int start_x, int end_y, int end_x) {
	queue<pair<int, int> > q;
	visited[start_y][start_x] = true;
	q.push(make_pair(start_y, start_x));
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		if(y == end_y && x == end_x) return;
		
		for(int dir=0; dir<8; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=l || nx<0 || nx>=l) continue;
			if(visited[ny][nx]) continue;
			value[ny][nx] = value[y][x] + 1;
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		memset(visited, false, sizeof(visited));
		memset(value, 0, sizeof(value));
		
		//INPUT
		scanf("%d", &l);
		int start_y, start_x;
		scanf("%d %d", &start_y, &start_x);
		int end_y, end_x;
		scanf("%d %d", &end_y, &end_x);
		
		bfs(start_y, start_x, end_y, end_x);
		
		printf("%d\n", value[end_y][end_x]);
	}
	
	return 0;
}
