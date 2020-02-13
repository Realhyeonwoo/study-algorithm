#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int T;
int N, M; // N: 국가의 수, M: 비행기의 종류 
vector<int> map[1001];

int value[1001];
bool visited[1001];
int check_bfs(int start) {
	int count = 0;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();

		for(int i=0; i<map[now].size(); i++) {
			int next = map[now][i];
			if(visited[next]) continue;
			visited[next] = true;
			count++;
			q.push(next);
		}
	}
	return count;
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++)  {
		scanf("%d %d", &N, &M); // 국가의 수, 비행기의 종류 입력
		for(int i=0; i<M; i++) {
			int num1, num2;
			scanf("%d %d", &num1, &num2);
			map[num1].push_back(num2);
			map[num2].push_back(num1);
		}
		
		memset(value, 0, sizeof(value));
		memset(visited, false, sizeof(visited));
		int answer = check_bfs(1);
		printf("%d\n", answer);
	}
	return 0;
}

/*
	for(int i=1; i<=N; i++) {
			printf("%d => ", i);
			for(int j=0; j<map[i].size(); j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
*/
