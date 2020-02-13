#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(void) {
	vector<int> answer;
	int N;
	scanf("%d", &N);
	
	// 카드 생성 
	queue<int> card;
	for(int i=1; i<=N; i++) {
		card.push(i);
	}
	
	// 시뮬레이션 
	while(card.size() != 1) {
		answer.push_back(card.front());
		card.pop();
		int move = card.front();
		card.pop();
		card.push(move);
	}
	
	// 결과출력 
	for(int i=0; i<answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	printf("%d\n", card.front());
	return 0;
}

