#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

#define INF 987654321
using namespace std;

int N, M;
vector<int> v[101];
bool visited[101];
int ans = INF;
int step; 

void dfs(int start, int end, int cnt) {
	printf("[%d, %d, %d]\n", start, end, cnt);
	if(start == end) {
		printf("start: %d, end: %d, cnt: %d\n", start, end, cnt);
		step = min(step, cnt);
		return;
	}
	
	for(int i=0; i<v[start].size(); i++) {
		int next = v[start][i];
		if(visited[next]) continue;
		
		visited[next] = true;
		printf("%d => ", start);
		dfs(next, end, cnt+1);
		visited[next] = false;
		printf("delete: %d\n", next);
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	
	//SIMULATION
	int person = 0;
	for(int i=1; i<=N; i++) {
		memset(visited, false, sizeof(visited));
		int sum = 0; 
		
		printf("########### start: %d ###############\n", i);
		for(int j=1; j<=N; j++) {
			if(i==j) continue;
			step = INF;
			
			dfs(i, j, 0);
			printf("============%d======\n", step);
			sum += step;
		}
		printf("======>>>>>> %d\n", sum);
		if(ans > sum) {
			ans = sum;
			person = i;
		} else if(ans == sum) {
			person = min(person, i);
		}
	}
	
	// OUTPUT
	printf("%d\n", person);
	
	return 0;
}
