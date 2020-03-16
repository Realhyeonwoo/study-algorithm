#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, a, b, m;
vector<int> node[101];
bool visited[101];
int value[101];

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
			value[next] = value[cur] + 1;
			q.push(next);
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	int x, y;
	for(int i=0; i<m; i++) {
		scanf("%d %d", &x, &y); // y의 부모인 x 
		node[x].push_back(y);
		node[y].push_back(x);
	}
	
	// SIMULATION
	bfs(a);
	
	// OUTPUT
	if(value[b] == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", value[b]);	
	}
	
	
	return 0;
}
