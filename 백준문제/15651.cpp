//중복순열 
#include<iostream>
#include<vector>
using namespace std;

bool visited[8] = {false, };
vector<int> V;

void Print(int n) {
	for(int i=0; i<V.size(); i++) {
		printf("%d ", V[i]);
	}
	printf("\n");
}
void Dfs(int cnt, int n, int m) {
	if(cnt == m) {
		Print(n);
		return;
	}
	
	for(int i=1; i<=n; i++) {
		V.push_back(i);
		Dfs(cnt+1, n , m);
		V.pop_back();		
	}
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	Dfs(0, n, m);
	return 0; 
}
