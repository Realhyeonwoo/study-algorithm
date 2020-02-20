#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std; 

int N, M, V; // 정점 수(N), 간선 수(M), 시작번호(V) 
vector<int> node[1001]; // 1 ~ 1000 번 정점

bool dfs_visited[1001];

void dfs(int start) {
	dfs_visited[start] = true;
	printf("%d ", start); 
	
	for(int i=0; i<node[start].size(); i++) {
		int next = node[start][i];
		if(dfs_visited[next]) continue;
		dfs(next);
	}
}

bool bfs_visited[1001];
void bfs(int start) {
	queue<int> q;
	q.push(start);
	bfs_visited[start] = true;
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		
		for(int i=0; i<node[cur].size(); i++) {
			int next = node[cur][i];
			if(bfs_visited[next]) continue;
			bfs_visited[next] = true;
			q.push(next);
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &N, &M, &V);
	for(int i=0; i<M; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		node[v1].push_back(v2);
		node[v2].push_back(v1);
	}
	
	for (int i = 1; i <= N; i++) {
		sort(node[i].begin(), node[i].end());
	}
	
	// DFS
	dfs(V);
	
	printf("\n");
	
	// BFS
	bfs(V);
}
