#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>

#define MAX 50
using namespace std;

int N, L, R;
int map[MAX][MAX];
int check[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool checkDistance(int a, int b) {
	return abs(a - b) >= L && abs(a - b) <= R ? true : false;
}

bool openDoorAndCalcPopulation_bfs(int y, int x, int index) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	check[y][x] = index;
	
	int count = 1;
	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
		
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(check[ny][nx] != 0) continue;
			if(checkDistance(map[cy][cx], map[ny][nx])) {
				check[ny][nx] = index;
				q.push(make_pair(ny, nx));
				count++;
			}
		}
	}
	
	if(count == 1) return false;
	else {
		// CALC_POPULATION
		int sum = 0;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(check[y][x] == index) {
					sum += map[y][x];
				}
			}
		}
		
		sum /= count;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(check[y][x] == index) {
					map[y][x] = sum;
				}
			}
		}
		return true;
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &N, &L, &R);
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// SIMULATION
	int answer = 0;
	while(1) {
		memset(check, 0, sizeof(check));
		int index = 1;
		bool isContinue = false;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(check[y][x] != 0) continue;
				if(openDoorAndCalcPopulation_bfs(y, x, index++)) isContinue = true;
			}
		}
		
		if(!isContinue) break;
		answer++;
	}
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
