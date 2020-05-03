#include<iostream>
#include<vector>
#define MAX 20
using namespace std;

int N, M, x, y, K;
int map[MAX][MAX];
vector<int> Answer;
pair<int, int> curPos;

int dice[7];
int Top = 1, Bottom = 2, Front = 3, Back = 4, Left = 5, Right = 6;

void checkMap(void) {
	if(map[curPos.first][curPos.second] == 0) {
		map[curPos.first][curPos.second] = dice[Bottom];
	} else {
		dice[Bottom] = map[curPos.first][curPos.second];
		map[curPos.first][curPos.second] = 0;
	}
	Answer.push_back(dice[Top]);	
}

void moveEast(void) {
	if(curPos.second+1 >= M) return;
	curPos.second += 1;
	
	int temp = Top;
	Top = Left;
	Left = Bottom;
	Bottom = Right;
	Right = temp;
	
	checkMap();	
}

void moveWest(void) {
	if(curPos.second-1 < 0) return;
	curPos.second -= 1;
	
	int temp = Top;
	Top = Right;
	Right = Bottom;
	Bottom = Left;
	Left = temp;
	
	checkMap();	
}

void moveNorth(void) {
	if(curPos.first-1 < 0) return;
	curPos.first -= 1;
	
	int temp = Top;
	Top = Front;
	Front = Bottom;
	Bottom = Back;
	Back = temp;

	checkMap();
}

void moveSouth(void) {
	if(curPos.first+1 >= N) return;
	curPos.first += 1;
	
	int temp = Top;
	Top = Back;
	Back = Bottom;
	Bottom = Front;
	Front = temp;
	
	checkMap();
}

int main(void) {
	// INPUT
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	curPos = {x, y};
	
	// SIMULATION
	int k;
	for(int i=0; i<K; i++) {
		scanf("%d", &k);
		
		if(k == 1) moveEast();
		else if(k == 2) moveWest();
		else if(k == 3) moveNorth();
		else if(k == 4) moveSouth();
	}
	
	// OUTPUT
	for(int i=0; i<Answer.size(); i++) printf("%d\n", Answer[i]);
	
	return 0;
}
