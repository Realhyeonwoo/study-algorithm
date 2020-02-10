#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
vector<int> computer[10001];
bool visited[10001] = {false, };
int count;
int answer[10001];

void hack_bfs(int start) {
	queue<int> q;
	q.push(start);
	
	while(!q.empty()) {
		int com = q.pop();
		
		count++;
		visited[com] = true;
		
		for(int i=0; i<computer[com].size(); i++) {
			int next = computer[com][i];
			if(visited[next]) continue;
			q.push(next);
		}
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
		hack_bfs(i);
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
