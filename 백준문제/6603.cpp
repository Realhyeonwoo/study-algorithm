#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int arr[13];
bool visited[13] = { false, };

void Print(int k) {
	for(int i=0; i<k; i++) {
		if(visited[i]) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

void Bfs(int idx, int cnt, int k) {
	if(cnt == 6) {
		Print(k); 
		return;
	}
	for(int i=idx; i<k; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		Bfs(i, cnt+1, k);
		visited[i] = false;
	}
}

int main(void) {
	int k;
	while(true) {
		scanf("%d", &k);		
		if(k == 0) break;
		for(int i=0; i<k; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+k);
		
		Bfs(0, 0, k);
		printf("\n");
		memset(visited, false, 13); 
	}
		
	return 0; 
}
