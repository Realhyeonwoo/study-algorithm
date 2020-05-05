#include<iostream>
#include<queue>
#define MAX 17
#define GARO 1
#define SERO 2
#define CROSS 3
using namespace std;

int N, Answer;
int map[MAX][MAX];
pair<int, int> pos;

typedef struct {
	int y, x, shape;
}Info;

void bfs() {
	queue<Info> q;
	q.push({pos.first, pos.second, GARO});
	
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int shape = q.front().shape;
		q.pop();
		
		if(y == N && x == N) {
			Answer++;
			continue;
		}
		
		if(shape == GARO) {
			if(x+1<=N && map[y][x+1] == 0) q.push({y, x+1, shape});
			if(x+1<=N && y+1<=N && map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0) q.push({y+1, x+1, CROSS});
		} else if(shape == SERO) {
			if(y+1<=N && map[y+1][x] == 0) q.push({y+1, x, shape});
			if(x+1<=N && y+1<=N && map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0) q.push({y+1, x+1, CROSS});
		} else if(shape == CROSS) {
			if(x+1<=N && map[y][x+1] == 0) q.push({y, x+1, GARO});
			if(y+1<=N && map[y+1][x] == 0) q.push({y+1, x, SERO});
			if(x+1<=N && y+1<=N && map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0) q.push({y+1, x+1, shape});
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	pos = {1, 2};
	
	// SIMULATION
	bfs();
	
	// OUTPUT
	printf("%d\n", Answer);
	return 0;
}
