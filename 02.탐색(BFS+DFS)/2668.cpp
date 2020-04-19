#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int num[101];
int startNum[101];
int visited[101];
vector<int> answer, temp;

void dfs(int start, int current) {
	if(visited[current] && start == current) {
		for(int i=0; i<temp.size(); i++) {
			answer.push_back(temp[i]);
		}
		return;
	}
	
	if(!visited[current]) {
		temp.push_back(current);
		visited[current] = true;
		dfs(start, num[current]);	
	}
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &num[i]);
		if(i == num[i]) {
			visited[i] = true;
			answer.push_back(i);
		}
	}
	
	for(int i=1; i<=N; i++)	 {
		if(visited[i]) continue;
		dfs(i, i);
		temp.clear();
	}
	
	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for(int i=0; i<answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
	
	return 0;
}
