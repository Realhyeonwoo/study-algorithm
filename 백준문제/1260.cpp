#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> node[1001];
bool visited[1001] = { false, };

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i=0; i<node[x].size(); i++) {
			int y = node[x][i];
			if(!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

void dfs(int start) {
	visited[start] = true;
	printf("%d ", start);
	for(int i=0; i<node[start].size(); i++) {
		int y = node[start][i];
		if(!visited[y]) {
			dfs(y);	
		}
	}
}

int main(void) {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	
	for(int i=1; i<=n; i++) {
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		node[temp1].push_back(temp2);
		node[temp2].push_back(temp1);
	}
	for(int i=1; i<=n; i++) {
		sort(node[i].begin(), node[i].end());
	}
	
	dfs(v); 
	printf("\n");
	memset(visited, false, sizeof(visited));
	bfs(v);
	
	return 0;
}
