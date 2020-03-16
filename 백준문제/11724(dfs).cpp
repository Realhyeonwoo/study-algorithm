#include<iostream>
#include<vector>
using namespace std;

int map[1001][1001];
int N, M;
bool visited[1001];

void dfs(int start) {
	visited[start] = true;
	for(int i=1; i<=N; i++) {
		if(map[start][i] == 0 || visited[i]) continue;
		dfs(i);
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		map[n1][n2] = 1;
		map[n2][n1] = 1;
	}
	
	// CHECK_DFS
	int count = 0;
	for(int i=1; i<=N; i++) {
		if(visited[i]) continue;
		dfs(i);	
		count++;
	}
	
	// OUTPUT
	printf("%d\n", count);
	
	return 0;
}
