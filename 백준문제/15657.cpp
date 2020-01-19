#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;
vector<int> store;

void Print(void) {
	for(int i=0; i<store.size(); i++) {
		printf("%d ", store[i]);
	}
	printf("\n");
}

void Dfs(int idx, int cnt, int n, int m) {
	if(cnt == m) {
		Print();
		return;
	}
	
	for(int i=idx; i<n; i++) {
		store.push_back(arr[i]);
		Dfs(i, cnt+1, n, m);
		store.pop_back();
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	
	Dfs(0, 0, n, m);
	return 0; 
}
