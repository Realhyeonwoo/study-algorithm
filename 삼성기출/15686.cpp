#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

#define MAX 51
#define INF 987564321
using namespace std;

typedef struct {
	int y, x;
} Point;

int N, M;
int map[MAX][MAX];
bool visited[14];
vector<Point> House, ChickenShop, Selected;
int answer = INF;

int getDistance(int hy, int hx, int cy, int cx) {
	return abs(hy - cy) + abs(hx - cx);
}
int calcChickenDistance() {
	int sum = 0;
	for(int i=0; i<House.size(); i++) {
		int distance = INF;
		for(int j=0; j<Selected.size(); j++) {
			int d = getDistance(House[i].y, House[i].x, Selected[j].y, Selected[j].x);
			distance = min(distance, d);
		}
		sum += distance;
		if(sum > answer) return INF;
	}
	
	return sum;	
}

void selectChickenShop_dfs(int start, int cnt) {
	if(cnt == M) {
		for(int i=0; i<ChickenShop.size(); i++) {
			if(!visited[i]) continue;
			Selected.push_back({ChickenShop[i].y, ChickenShop[i].x});
		}
		answer = min(answer, calcChickenDistance());
			Selected.clear();
		return;
	}
	
	for(int i=start; i<ChickenShop.size(); i++) {
		if(visited[i]) continue;
		visited[i] = true;
		selectChickenShop_dfs(i, cnt + 1);
		visited[i] = false;
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == 1) House.push_back({y, x});
			else if(map[y][x] == 2) ChickenShop.push_back({y, x});
		}
	}
	
	// SIMULATION
	selectChickenShop_dfs(0, 0);
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
