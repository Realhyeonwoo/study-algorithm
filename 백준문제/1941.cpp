#include<iostream>
#define MAX 5
using namespace std;

char map[MAX][MAX];
bool visited[MAX][MAX];
int Answer = 0;

void dfs(int y, int x, int som, int total) {
	visited[y][x] = true;
	
	if(total == 7) {
		if(som >= 4) Answer++;
		return;
	}
	
	if(y+1 < MAX) {
		visited[y+1][x] = true;
		
		visited[y+1][x] = false;
		
	}
	
	if(x+1 < MAX) {
		
	}
}

int main(void) {
	// INPUT
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	
	// SIMULATION
	for(int y=0; y<MAX; y++) {
		for(int x=0; x<MAX; x++) {
			dfs(y, x, 0, 0);
		}
	}
	
	// OUTPUT
	printf("%d\n", Answer);
	return 0;
}
