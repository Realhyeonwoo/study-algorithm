#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 20
using namespace std;

int D, W, K, Answer;
int map[MAX][MAX], cpyMap[MAX][MAX];
bool visited[MAX];

bool isPassed() {
	for(int x=0; x<W; x++) {
		int aCnt = 0, bCnt = 0;
		bool isFlag = false;
		
		for(int y=0; y<D; y++) {
			if(cpyMap[y][x] == 0) {
				aCnt++;
				bCnt = 0;
			} else {
				aCnt = 0;
				bCnt++;
			}
			
			if(aCnt == K || bCnt == K) {
				isFlag = true;
				break;
			}
		}
		if(!isFlag) return false;
	}
	return true;
}

void doInjection(int idx, int value, bool b) {
	if(b)	{
		for(int i=0; i<W; i++) cpyMap[idx][i] = value;
	} else {
		for(int i=0; i<W; i++) cpyMap[idx][i] = map[idx][i];
	}
}

void dfs(int start, int cnt) {
	if(cnt >= Answer || cnt > K) return;	
	if(isPassed()) {
		Answer = min(Answer, cnt);
		return;
	}
	
	for(int i=start; i<D; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		for(int j=0; j<2; j++) {
			doInjection(i, j, true);
			dfs(i, cnt+1);
			doInjection(i, j, false);
		}
		visited[i] = false;
	}
}

int main(void) {
	int T; scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		Answer = 987564321;
		memset(visited, false, sizeof(visited));
		
		// INPUT
		scanf("%d %d %d", &D, &W, &K);
		for(int y=0; y<D; y++) {
			for(int x=0; x<W; x++) {
				scanf("%d", &map[y][x]);
				cpyMap[y][x] = map[y][x];
			}
		}
		
		// SIMULATION
		if(K == 1) {
			Answer = 0;
		} else {
			dfs(0, 0);
		}
		
		// OUTPUT
		printf("#%d %d\n", tc, Answer);
	}
	return 0;
}
