#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;
bool visited[8] = {false, };

void Print(int n) {
	for(int i=0; i<n; i++) {
		if(visited[i]) {
			printf("%d ", arr[i]);
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
		if(visited[i]) continue;
		visited[i] = true;
		Dfs(i, cnt+1, n, m);
		visited[i] = false;
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
