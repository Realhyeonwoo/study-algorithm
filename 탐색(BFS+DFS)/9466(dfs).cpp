#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int T, n, answer;
int node[100001];
int startNode[100001];
int visited[100001];

int dfs(int start, int current, int count) {
	if(visited[current] != 0) {
		return start == startNode[current] ? count - visited[current] : 0;
	}
	startNode[current] = start;
	visited[current] = count;
	return dfs(start, node[current], count + 1);
}

int main(void) {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// RESET 
		memset(startNode, 0, sizeof(startNode));
		memset(visited, 0, sizeof(visited));
		answer = 0;
		
		// INPUT
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &node[i]);
		}
		
		// SIMULATION
		for(int i=1; i<=n; i++) {
			if(visited[i] == 0) {
				answer += dfs(i, i, 1);
			}
		}
		
		// OUTPUT
		printf("%d\n", n - answer);
	}
	return 0;
}
