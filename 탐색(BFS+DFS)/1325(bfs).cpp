#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
vector<int> node[10001];
bool visited[10001];
int count;
int maxValue = -987654321;
int answer[10001];

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		for(int i=0; i<node[now].size(); i++) {
			int next = node[now][i];
			
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
			count++;
		}
	}
	
}
int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	int n1, n2;
	for(int i=0; i<M; i++) {
		scanf("%d %d", &n1, &n2);
		node[n2].push_back(n1);
	}
	
	// SIMULATION
	for(int i=1; i<=N; i++) {
		memset(visited, false, sizeof(visited));
		count = 1; 
		bfs(i);
		answer[i] = count;
		if(count >= maxValue) {
			maxValue = count;
		}
	}
	
	// OUTPUT
	for(int i=1; i<=N; i++) {
		if(answer[i] == maxValue) {
			printf("%d ", i);
		}
	}
	return 0;
}
