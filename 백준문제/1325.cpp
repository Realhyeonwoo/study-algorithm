#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int N, M;
vector<int> computer[10001]; // ��ǻ��: 1�� ~ 10000��
bool visited[10001] = {false, };
int answer[10001] = {0, };
int count = 0; 

void dfs(int start) {
	count += computer[start].size();
	visited[start] = true;
	
	if(computer[start].size() == 0) {
		return;
	}
	
	for(int i=0; i<computer[start].size(); i++) {
		int next = computer[start][i];
		if(visited[next]) continue;
		dfs(next);
	}
}

int main(void) {
	// �Է� 
	scanf("%d %d", &N, &M);
	for(int i=1; i<=M; i++)	 {
		int com1, com2;
		scanf("%d %d", &com1, &com2);
		computer[com2].push_back(com1);
	}
	
	// 1�� ��ǻ�ͺ��� Ž�� 
	for(int i=1; i<=N; i++) {
		memset(visited, false, sizeof(visited));
		count = 1;
		dfs(i);
		answer[i] = count;
	}
	
	// �ִ� ���ϱ� 
	int maxValue = answer[1];
	for(int i=2; i<=N; i++) {
		if(maxValue < answer[i]) {
			maxValue = answer[i];
		}
	}

	for(int i=1; i<=N; i++) {
		if(answer[i] == maxValue) {
			printf("%d ", i);
		}
	}
	return 0;	
}
