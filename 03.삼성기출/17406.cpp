#include<iostream>
#include<vector>
#define MAX 51
#define INF 987564321
using namespace std;

typedef struct {
	int r, c, s;
}Info;

int N, M, K, Answer=INF;
int map[MAX][MAX];
vector<Info> v;
vector<int> vIdx;
bool visited[6];

void copyMap(int origin[MAX][MAX], int cpy[MAX][MAX]) {
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=M; x++) {
			cpy[y][x] = origin[y][x];
		}
	}
}

void doRotate(int tempMap[][MAX], int tempMap2[][MAX], int y1, int x1, int y2, int x2) {
	while(y2 != y1 && x2 != x1) {
		for(int x=x1+1; x<x2; x++) {
			tempMap[y1][x] = tempMap2[y1][x-1];
			tempMap[y2][x] = tempMap2[y2][x+1];
		}
		for(int y=y1+1; y<y2; y++) {
			tempMap[y][x1] = tempMap2[y+1][x1];
			tempMap[y][x2] = tempMap2[y-1][x2];
		}
		tempMap[y1][x1] = tempMap2[y1+1][x1];
		tempMap[y1][x2] = tempMap2[y1][x2-1];
		tempMap[y2][x1] = tempMap2[y2][x1+1];
		tempMap[y2][x2] = tempMap2[y2-1][x2];
		
		y1 += 1;
		x1 += 1;
		y2 -= 1;
		x2 -= 1;
		
		copyMap(tempMap, tempMap2);
	}
}

int getValue(int tempMap[][MAX]) {
	int ans = INF;
	for(int y=1; y<=N; y++) {
		int sum = 0;
		for(int x=1; x<=M; x++) {
			sum += tempMap[y][x];
		}
		ans = min(ans, sum);
	}
	return ans;
}

void dfs(int cnt) {
	if(cnt == v.size()) {
		int tempMap[MAX][MAX], tempMap2[MAX][MAX];
		// copyMap
		copyMap(map, tempMap);
		copyMap(map, tempMap2);
		
		for(int i=0; i<vIdx.size(); i++) {
			int y1 = v[vIdx[i]].r - v[vIdx[i]].s;
			int x1 = v[vIdx[i]].c - v[vIdx[i]].s;
			int y2 = v[vIdx[i]].r + v[vIdx[i]].s;
			int x2 = v[vIdx[i]].c + v[vIdx[i]].s;
			
			// doRotate
			doRotate(tempMap, tempMap2, y1, x1, y2, x2);
		}
		
		// getMinValue
		Answer = min(Answer, getValue(tempMap));
		return;
	}
	
	for(int i=0; i<v.size(); i++) {
		if(visited[i]) continue;
		visited[i] = true;
		vIdx.push_back(i);
		dfs(cnt + 1);
		visited[i] = false;
		vIdx.pop_back();
	}
}
int main(void) {
	// INPUT
	scanf("%d %d %d", &N, &M, &K);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=M; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	int r, c, s;
	for(int i=0; i<K; i++) {
		scanf("%d %d %d", &r, &c, &s);
		v.push_back({r, c, s});
	}
	
	// SIMULATION
	dfs(0);
	
	// OUTPUT
	printf("%d\n", Answer);
	return 0;
}
