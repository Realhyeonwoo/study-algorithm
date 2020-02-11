#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int M, N, K; // M:세로(y), N:가로(x)
int map[100][100];
bool visited[100][100];

void dfs(int y, int x, int space) {
	visited[y][x] = true;
	map[y][x] = space;
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
		if(visited[ny][nx]) continue;
		if(map[ny][nx] != 0) continue;
		map[ny][nx] = space;
		visited[ny][nx] = true;
		dfs(ny, nx, space);
	}
}

int main(void) {
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	// 입력 
	scanf("%d %d %d", &M, &N, &K);
	for(int i=0; i<K; i++) {
		int y1, x1, y2, x2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int y=y1; y<=y2-1; y++) {
			for(int x=x1; x<=x2-1; x++) {
				map[y][x] = 1;
			}
		}
	}

	// 탐색 
	int space = -1;
	for(int y=0; y<M; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == 0) {
				dfs(y, x, space);	
				space--;
			}
		}
	}
	
	// 나눠진 구역확인 
	vector<int> answer;
	for(int s=-1; s>space; s--) {
		int count = 0;
		for(int y=0; y<M; y++) {
			for(int x=0; x<N; x++) {
				if(map[y][x] == s) {
					count++;
				}	
			}
		}
		answer.push_back(count);
	}

	// 정답 출력 
	sort(answer.begin(), answer.end());
	
	printf("%d\n", answer.size());
	for(int i=0; i<answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	
	
	return 0;
}
