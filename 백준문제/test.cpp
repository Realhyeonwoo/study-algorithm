#include<iostream>
using namespace std;

int gameResult[4][18];
int valid;
vector<int> Answer;

// 0 1 2 3 4 5
void dfs(int t1, int t2, int r) {
	if(t2 == 6) {
		dfs(t1+1, t1+2, r);
		return;
	}
	
	if(t1 > 4) {
		for(int c=0; c<gameResult[r].length; c++) {
			if(gameResult[r][c] > 0) {
				valid = 0;
				return;
			}
		}
		valid = 1;
		return;
	}
	
	
}

int main(void) {
	for(int r=0; r<4; r++) {
		for(int c=0; c<18; c++) {
			scanf("%d", &gameResult[r][c]);
		}
		valid = 0;
		dfs(0, 1, r);
		Answer.push_back(valid);
	}
	
	for(int i=0; i<Answer.size(); i++) printf("%d ", Answer[i]);
	return 0;
}
