#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int M, N; // M:세로(y) N:가로(x) 
int ay, ax;
int map[101][101];
int visited[101][101] = {0, };

void dfs(int y, int x) {
	
}

int main(void) {
	scanf("%d %d", &M, &N);
	scanf("%d %d", &ay, &ax);
	for(int y=0; y<M; y++)	 {
		for(int x=0; x<N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	dfs(0, 0);
	
	
	return 0;
}
