#include<iostream> 
#include<cstring>
using namespace std;

int T;
int answer = 0;
bool visited[31];

void selectBridge_dfs(int start, int cnt, int N, int M) {
	if(cnt == N) {
		answer++;
		for(int i=1; i<=M; i++) {
			if(visited[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");
		return;
	}
	
	for(int i=start; i<=M; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		selectBridge_dfs(i, cnt+1, N, M);
		visited[i] = false;
	}
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		int N, M;
		scanf("%d %d", &N, &M);
		
		answer = 0; 
		memset(visited, false, sizeof(visited));
		selectBridge_dfs(1, 0, N, M);
		
		printf("%d\n", answer);
	}
	return 0; 
}
