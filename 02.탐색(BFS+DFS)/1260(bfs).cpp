#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, V;
vector<int> map[1001];
bool visited[1001];

void dfs(int start) {
	for(int i=0; i<map[start].size(); i++) {
		int next = map[start][i];
		if(visited[next]) continue;
		visited[next] = true;
		printf("%d ", next);
		dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		visited[now] = true;
		printf("%d ", now);
		
		for(int i=0; i<map[now].size(); i++) {
			int next = map[now][i];
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}
int main(void) {
	// INPUT
	scanf("%d %d %d", &N, &M, &V);
	int n1, n2;
	for(int i=0; i<M; i++) {
		scanf("%d %d", &n1, &n2);
		map[n1].push_back(n2);
		map[n2].push_back(n1);
	}
	for(int i=1; i<=N; i++) {
		sort(map[i].begin(), map[i].end()); 
	}
	
	//DFS
	visited[V] = true;
	printf("%d ", V);
	dfs(V);	
	
	memset(visited, false, sizeof(visited));
	printf("\n");
	
	//BFS
	bfs(V);
	return 0;
}
