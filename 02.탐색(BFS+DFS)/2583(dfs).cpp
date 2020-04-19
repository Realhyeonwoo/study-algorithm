#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int M, N, K;
int map[100][100];
int space;
bool visited[100][100];
vector<int> answer; 

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void check_dfs(int y, int x) {
	visited[y][x] = true;
	map[y][x] = 1; 
	space++; 
	
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
		if(map[ny][nx] == 1) continue;
		
		check_dfs(ny, nx);
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &M, &N, &K);
	for(int i=0; i<K; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int y=y1; y<=y2-1; y++) {
			for(int x=x1; x<=x2-1; x++) {
				map[y][x] = 1;
			}
		}
	}
	
	// SIMULATION
	for(int y=0; y<M; y++) {
		for(int x=0; x<N; x++) {
			space = 0;
			memset(visited, false, sizeof(visited));
			
			if(map[y][x] == 0) {
				check_dfs(y, x);
				answer.push_back(space);
			}
		}
	}
	
	// OUTPUT
	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for(int i=0; i<answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	
	return 0;
}
