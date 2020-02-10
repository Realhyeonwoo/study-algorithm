#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<math.h>
using namespace std;

int N, M, D; // N:세로(y), M:가로(x), D:공격거리 
int map[16][16] = {0, }; // 0 ~ 15 ( 0 ~ (N-1)번째까지 맵  /   N번째 줄에 궁수 배치) 
bool visited[15] = {false, };
vector<pair<int, int> > archer;
int backup[16][16];
vector<int> answer;

int goUp(int ay, int ax) {	
	int kill_y = -1, kill_x = -1;
	int minDist = ay + D + M;
	for(int y=ay-1; y>=0; y--) {
		for(int x=0; x<M; x++) {
			if(map[y][x] == 0) continue;
			int dist = abs(ay - y) + abs(ax - x);
			if(dist<=D && minDist>dist) {
				minDist = dist;
				kill_y = y;
				kill_x = x;
			}
		}
	}
	
	if(kill_y == -1) {
		return 0;
	} else {
		if(backup[kill_y][kill_x] == 0) return 0;
		backup[kill_y][kill_x] = 0;
		return 1;
	}
}

void simulation() {
	int kill = 0; 
	
	for(int y=N; y>=1; y--) {
		for(int x=0; x<M; x++) {
			if(backup[y][x] == 2) {
				kill += goUp(y, x);
			}
		}
		// 궁수들 한 칸 위로 이동 	
		for(int x=0; x<M; x++) {
			backup[y-1][x] = backup[y][x];
		}
	}
	
	
	answer.push_back(kill);
}

void archer_dfs(int idx, int cnt) {
	if(cnt == 3) {
		for(int i=0; i<M; i++) {
			if(visited[i]) {
				archer.push_back(make_pair(N, i));
			}
		}
		
		// copy map 
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				backup[y][x] = map[y][x];
			}
		}
		// put archer
		for(int i=0; i<archer.size(); i++) {
			int y = archer[i].first;
			int x = archer[i].second;
			backup[y][x] = 2;
		}
	
		simulation();
		
		archer.clear();
		memset(backup, 0, sizeof(backup));
		return;
	}
	
	for(int i=idx; i<M; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		archer_dfs(i, cnt+1);
		visited[i] = false;
	}
	
}

int main(void) {
	// 입력 
	scanf("%d %d %d", &N, &M, &D); 
	for(int y=0; y<N; y++){
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// 궁수 배치(0 ~ M-1 중 3개 뽑기)
	archer_dfs(0, 0);
	
	int maxValue = -1;
	for(int q=0; q<answer.size(); q++) {
		if(maxValue < answer[q]) {
			maxValue = answer[q];
		}
	}
	
	printf("%d\n", maxValue);
	
	return 0;
}
