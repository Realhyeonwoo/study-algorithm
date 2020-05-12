#include<iostream>
#include<vector>
#define ROW 4
#define COL 18
using namespace std;

int map[ROW][COL], valid;
vector<int> Answer;

// 0 1 2 3 4 5 
void dfs(int t1, int t2, int game[]) {
	if(t1 > 4) {
		for(int i=0; i<COL; i++) {
			if(game[i] > 0) return;
		}
		valid = 1;
		return;
	}
	
	if(t2 == 6) {
		dfs(t1+1, t1+2, game);
		return;
	}
	
	if(game[t1*3 + 0] > 0 && game[t2*3 + 2] > 0) {
		game[t1*3 + 0]--;
		game[t2*3 + 2]--;
		dfs(t1, t2+1, game);
		game[t1*3 + 0]++;
		game[t2*3 + 2]++;
	}
	
	if(game[t1*3 + 1] > 0 && game[t2*3 + 1] > 0) {
		game[t1*3 + 1]--;
		game[t2*3 + 1]--;
		dfs(t1, t2+1, game);
		game[t1*3 + 1]++;
		game[t2*3 + 1]++;
	}
	
	if(game[t1*3 + 2] > 0 && game[t2*3 + 0] > 0) {
		game[t1*3 + 2]--;
		game[t2*3 + 0]--;
		dfs(t1, t2+1, game);
		game[t1*3 + 2]++;
		game[t2*3 + 0]++;
	}
	
}

int main(void) {
	// INPUT
	for(int y=0; y<ROW; y++) {
		for(int x=0; x<COL; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	// SIMULATION
	for(int y=0; y<ROW; y++) {
		valid = 0;
		dfs(0, 1, map[y]);
		Answer.push_back(valid);
	}
	
	
	// OUTPUT
	for(int i=0; i<Answer.size(); i++) {
		printf("%d ", Answer[i]);
	}
	return 0;
}
