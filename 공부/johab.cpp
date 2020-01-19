#include<iostream>
#include<vector>
using namespace std;

bool visited[8];

void Print(int n) {
	for(int i=0; i<n; i++) {
		if(visited[i] == true) {
			printf("%d ", (i+1));
		}
	}
	printf("\n");
}

void Dfs(int idx, int cnt, int n, int m) {
	if(cnt == m) {
		Print(n);
		return;
	}
	
	for(int i=idx; i<n; i++) {
		if(visited[i] == true) continue;
		visited[i] = true;
		Dfs(i, cnt+1, n, m);
		visited[i] = false;
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	Dfs(0, 0, n, m);
	return 0; 
	
}
