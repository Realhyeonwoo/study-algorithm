#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool visited[13];

void pickNum_dfs(int start, int cnt, vector<int> number) {
	if(cnt == 6) {
		for(int i=0; i<13; i++) {
			if(visited[i]) {
				printf("%d ", number[i]);
			}
		}
		printf("\n");
		return;
	}
	
	for(int i=start; i<number.size(); i++) {
		if(visited[i]) continue;
		visited[i] = true;
		pickNum_dfs(i, cnt+1, number);
		visited[i] = false;
	}
	
}
int main(void) {
	while(true) {
		int k;
		vector<int> number;
		memset(visited, false, sizeof(visited));
		
		scanf("%d", &k);
		if(k == 0) break;
		
		for(int i=0; i<k; i++) {
			int num;
			scanf("%d", &num);
			number.push_back(num);
		}
		
		pickNum_dfs(0, 0, number);
		printf("\n");
	}
	return 0;
}
