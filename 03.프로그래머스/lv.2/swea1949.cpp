#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

#define MAX 8
using namespace std;

int N, K, Answer;
int map[MAX][MAX], cpyMap[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int> > v;
int Max, Min;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void copyMap(void) {
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			cpyMap[y][x] = map[y][x];
		}
	}
}

void dfs(int y, int x, int m[][MAX], int cnt) {
	Answer = max(Answer, cnt);
	visited[y][x] = true;
	
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
		if(visited[ny][nx]) continue;
		if(m[ny][nx] >= m[y][x]) continue;
		
		dfs(ny, nx, m, cnt+1);
	}
	visited[y][x] = false;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		Answer = 0;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		v.clear();
		Max = -1;
		Min = 987654321;
		
		// INPUT
		scanf("%d %d", &N, &K);
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				scanf("%d", &map[y][x]);
				Max = max(Max, map[y][x]);
				Min = min(Min, map[y][x]);
			}
		}
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(Max == map[y][x]) v.push_back(make_pair(y, x));
			}
		}
		
		// SIMULATION
		for(int i=0; i<v.size(); i++) {
			int y = v[i].first;
			int x = v[i].second;
			dfs(y, x, map, 1);
		}
		
		for(int i=0; i<v.size(); i++) {
			int cy = v[i].first;
			int cx = v[i].second;
			
			copyMap();
			
			for(int y=0; y<N; y++) {
				for(int x=0; x<N; x++) {
					if(map[y][x] == Min) continue;
					if(y == cy && cx == x) continue;
					
					for(int t=1; t<=K; t++) {
						cpyMap[y][x] = cpyMap[y][x] - K;
						dfs(cy, cx, cpyMap, 1);
						cpyMap[y][x] = cpyMap[y][x] + K;
					}
				}
			}
		}
		
		// OUTPUT
		printf("#%d %d\n", tc, Answer);
	}
	return 0;
}
