#include<iostream>
#include<vector>
using namespace std;

bool visited[9];
vector<int> check;

void Print() {
	for(int i=0; i<check.size(); i++) {
		printf("%d ", check[i]);
	}
	printf("\n");
}

void Dfs(int cnt, int n, int m) {
	if(cnt == m) {
		Print(); 
		return;
	}
	
	for(int i=0; i<n; i++) {
		if(visited[i] == true) continue;
		visited[i] = true;
		check.push_back(i+1);
		Dfs(cnt+1, n, m);
		check.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	Dfs(0, n, m);
	return 0;
}
