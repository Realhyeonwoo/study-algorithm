#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
vector<int> node[100];
bool visited[100];
int value[100];
int maxValue = 987654321;
int answer;

int bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for(int i=0; i<node[cur].size(); i++) {
			int next = node[cur][i];
			if(visited[next]) continue;
			visited[next] = true;
			value[next] = value[cur] + 1;
			q.push(next);
		}
	}
	
	int sum = 0;
	for(int i=1; i<=N; i++) {
		sum += value[i];
	}
	return sum;
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	int n1, n2;
	for(int i=0; i<M; i++) {
		scanf("%d %d", &n1, &n2);
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}
	
	// SIMULATION
	for(int i=1; i<=N; i++) {
		memset(visited, false, sizeof(visited));
		memset(value, 0, sizeof(value));
		
		int res = bfs(i);
		if(maxValue > res) {
			maxValue = res;
			answer = i;
		}
	}
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
