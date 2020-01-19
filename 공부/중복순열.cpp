#include<iostream>
#include<vector>
using namespace std;

bool visited[7] = {false, };
vector<int> store;

void Print() {
	for(int i=0; i<store.size(); i++) {
		printf("%d ", store[i]);
	}
	printf("\n");
}

void Dfs(int cnt, int n, int m) {
	if(cnt == m) {
		Print();
		return; 
	}
	
	for(int i=0; i<n; i++) {
		store.push_back(i+1);
		Dfs(cnt+1, n, m);
		store.pop_back();
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	Dfs(0, n, m);
	
	return 0;
}

