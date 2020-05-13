#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10
#define INF 9875654321
using namespace std;

int map[MAX][MAX], Answer = INF;
bool visited[MAX][MAX];
vector<pair<int, int> > v;

bool canFill(int y, int x, int r) {
	int sum = 0;
	for(int i=y; i<y+r; i++) {
		if(i >= MAX) break;
		for(int j=x; j<x+r; j++) {
			if(j >= MAX) break;
			if(map[i][j] == 1) sum++;
		}
	}
	
	return sum == r*r ? true : false;
}

int checkSize(int y, int x) {
	if(canFill(y, x, 2))	{
		if(canFill(y, x, 3))	{
			if(canFill(y, x, 4))	{
				if(canFill(y, x, 5))	{
					return 5;
				}
				return 4;
			}
			return 3;
		}	
		return 2;
	}
	return 1;
}

void makeVisit(int y, int x, int r, bool b) {
	for(int i=y; i<y+r; i++) {
		for(int j=x; j<x+r; j++) {
			visited[i][j] = b;
		}
	}
}

void dfs(int idx, int One, int Two, int Three, int Four, int Five, int totalCnt) {
	int usedCount = One + Two + Three + Four + Five;
	
	if(Answer < usedCount) return;
	
	if(totalCnt == v.size()) {
		Answer = min(Answer, usedCount);
		return;
	}
	
	if(visited[v[idx].first][v[idx].second]) {
		dfs(idx+1, One, Two, Three, Four, Five, totalCnt);
		return;
	}
	
	int size = checkSize(v[idx].first, v[idx].second);
	if(size == 1) {
		if(One+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 1, true);
			dfs(idx+1, One+1, Two, Three, Four, Five, totalCnt+1);
			makeVisit(v[idx].first, v[idx].second, 1, false);
		}
	} else if(size == 2) {
		if(Two+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 2, true);
			dfs(idx+1, One, Two+1, Three, Four, Five, totalCnt+4);
			makeVisit(v[idx].first, v[idx].second, 2, false);
		}
		if(One+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 1, true);
			dfs(idx+1, One+1, Two, Three, Four, Five, totalCnt+1);
			makeVisit(v[idx].first, v[idx].second, 1, false);
		}
	} else if(size == 3) {
		if(Three+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 3, true);
			dfs(idx+1, One, Two, Three+1, Four, Five, totalCnt+9);
			makeVisit(v[idx].first, v[idx].second, 3, false);
		}
		if(Two+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 2, true);
			dfs(idx+1, One, Two+1, Three, Four, Five, totalCnt+4);
			makeVisit(v[idx].first, v[idx].second, 2, false);
		}
		if(One+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 1, true);
			dfs(idx+1, One+1, Two, Three, Four, Five, totalCnt+1);
			makeVisit(v[idx].first, v[idx].second, 1, false);
		}
	} else if(size == 4) {
		if(Four+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 4, true);
			dfs(idx+1, One, Two, Three, Four+1, Five, totalCnt+16);
			makeVisit(v[idx].first, v[idx].second, 4, false);
		}
		if(Three+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 3, true);
			dfs(idx+1, One, Two, Three+1, Four, Five, totalCnt+9);
			makeVisit(v[idx].first, v[idx].second, 3, false);
		}
		if(Two+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 2, true);
			dfs(idx+1, One, Two+1, Three, Four, Five, totalCnt+4);
			makeVisit(v[idx].first, v[idx].second, 2, false);
		}
		if(One+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 1, true);
			dfs(idx+1, One+1, Two, Three, Four, Five, totalCnt+1);
			makeVisit(v[idx].first, v[idx].second, 1, false);
		}
	} else if(size == 5) {
		if(Five+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 5, true);
			dfs(idx+1, One, Two, Three, Four, Five+1, totalCnt+25);
			makeVisit(v[idx].first, v[idx].second, 5, false);
		}
		if(Four+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 4, true);
			dfs(idx+1, One, Two, Three, Four+1, Five, totalCnt+16);
			makeVisit(v[idx].first, v[idx].second, 4, false);
		}
		if(Three+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 3, true);
			dfs(idx+1, One, Two, Three+1, Four, Five, totalCnt+9);
			makeVisit(v[idx].first, v[idx].second, 3, false);
		}
		if(Two+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 2, true);
			dfs(idx+1, One, Two+1, Three, Four, Five, totalCnt+4);
			makeVisit(v[idx].first, v[idx].second, 2, false);
		}
		if(One+1 <= 5) {
			makeVisit(v[idx].first, v[idx].second, 1, true);
			dfs(idx+1, One+1, Two, Three, Four, Five, totalCnt+1);
			makeVisit(v[idx].first, v[idx].second, 1, false);
		}
	}
}

int main(void) {
	// INPUT
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x]) v.push_back(make_pair(y, x));
		}
	}
	
	// SIMULATION
	if(v.size() == 0) {
		Answer = 0;
	} else {
		dfs(0, 0, 0, 0, 0, 0, 0);
		if(Answer == INF) Answer = -1;
	}
	
	// OUTPUT
	printf("%d\n", Answer);
	return 0;
}
