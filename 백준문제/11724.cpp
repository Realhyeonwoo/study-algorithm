#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> arr[1001];
bool visited[1001];

void Bfs(int start) {
	queue<int> q;
	
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(int i=0; i<arr[x].size(); i++) {
			int y = arr[x][i];
			if(!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}
	
	int count = 0; 
	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			Bfs(i);	
			count++;
		}
	}
	printf("%d\n", count);
	
	return 0;
}
