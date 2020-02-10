#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int N, M;
vector<int> computer[10001];
bool visited[10001] = {false, };
int count;
int answer[10001];

void hack_dfs(int start) {
	count++;
	visited[start] = true;

	for(int i=0; i<computer[start].size(); i++) {
		int next = computer[start][i];
		if(visited[next]) continue;
		hack_dfs(next);
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		computer[b].push_back(a); // a가 b를 신뢰한다 === b해킹-> a해킹  
	}
	
	int maxV = -1;
	for(int i=1; i<=N; i++) {
		count = 0;
		memset(visited, false, sizeof(visited));
		hack_dfs(i);
		if(maxV < count) {
			maxV = count;
		}
		answer[i] = count;
	}
	
	for(int i=1; i<=N; i++) {
		if(maxV == answer[i]) {
			printf("%d ", i);	
		}
	}
	
	return 0;
	
}
