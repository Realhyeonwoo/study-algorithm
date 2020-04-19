#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
vector<int> node[1001];
bool visited[1001];

void bfs(int start) {
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
			q.push(next);
		}
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	
	int count = 0;
	for(int i=1; i<=N; i++) {
		if(visited[i]) continue;
		bfs(i);
		count++;
	}	
	
	printf("%d\n", count);
	return 0;
}
