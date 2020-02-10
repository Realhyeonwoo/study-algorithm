//중복조합 
#include<iostream>
using namespace std; 

int visited[10];

void Print(int m) {
	for(int i=0; i<m; i++) {
		printf("%d ", visited[i]);
	}
	printf("\n");
}

void Dfs(int idx, int cnt, int n, int m) {
	if(cnt == m) {
		Print(m);
		return;
	}
	
	for(int i=idx; i<n; i++) {
		visited[cnt] = i+1;
		Dfs(i, cnt+1, n, m);
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	Dfs(0, 0, n, m);
	
	return 0; 
}
