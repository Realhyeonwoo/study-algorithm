#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(void) {
	vector<int> answer;
	int N;
	scanf("%d", &N);
	
	// ī�� ���� 
	queue<int> card;
	for(int i=1; i<=N; i++) {
		card.push(i);
	}
	
	// �ùķ��̼� 
	while(card.size() != 1) {
		answer.push_back(card.front());
		card.pop();
		int move = card.front();
		card.pop();
		card.push(move);
	}
	
	// ������ 
	for(int i=0; i<answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	printf("%d\n", card.front());
	return 0;
}

