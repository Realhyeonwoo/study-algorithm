#include<iostream>
#include<vector>
using namespace std;

vector<int> store;

void Print(int n) {
	for(int i=0; i<store.size(); i++) {
		printf("%d ", store[i]);		
	}
	printf("\n");
}

void Dfs(int idx, int cnt, int n, int m) {
	if(cnt == m) {
		Print(n); 
		return; 
	}
	for(int i=idx; i<n; i++) {
		store.push_back(i+1);
		Dfs(i, cnt+1, n, m);
		store.pop_back();
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	Dfs(0, 0, n, m);
	
	return 0; 
}

