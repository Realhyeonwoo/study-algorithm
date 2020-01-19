#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> value;
bool visited[8] = {false, };
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
		if(visited[i]) continue;
		visited[i] = true;
		store.push_back(value[i]);
		Dfs(cnt+1, n, m);
		store.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n , &m);
	for(int i=0; i<n; i++){
		int temp;
		scanf("%d", &temp);
		value.push_back(temp);
	}
	
	sort(value.begin(), value.end());
	
	Dfs(0, n, m);
	
	return 0; 
}
