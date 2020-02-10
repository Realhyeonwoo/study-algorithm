#include<iostream>
using namespace std;

int N; // N¸í(Â¦¼ö)
int player[21][21]; // 1¹ø ~ 20¹ø
bool visited[21];

void dfs(int start, int count) {
	if(count == N/2) {
		printf("\n\n");
		for(int i=1; i<=N; i++) {
			if(visited[i]) {
				printf("trueÆÀ: %d \n", i);
			} else {
				printf("falseÆÀ: %d \n", i);
			}
		}
		printf("\n\n");
		return;
	}
	
	for(int i=start; i<=N; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		dfs(i, count+1);
		visited[i] = false;
	}
}
int main(void) {
	scanf("%d", &N);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &player[y][x]);
		}
	}
	
	dfs(1, 0);
	return 0;
}
