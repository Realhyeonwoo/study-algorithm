#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define MAX 100
using namespace std;

int N;
int num[MAX + 1];
bool visited[MAX + 1];
bool check[MAX + 1];
vector<int> answer, v;

void dfs(int start, int cur) {
	if(visited[cur]) {
		if(start != cur) v.clear();
		return;
	}
	visited[cur] = true;
	v.push_back(cur);
	dfs(start, num[cur]);
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	int n;
	for(int i=1; i<=N; i++) {
		scanf("%d", &n);
		num[i] = n;
		if(i == n) {
			answer.push_back(n);
			check[i] = true;
		}
	}
	
	// SIMULATION
	for(int i=1; i<=N; i++) {
		for(int i=1; i<=N; i++) visited[i] = false;
		
		dfs(i, i);
		for(int i=0; i<v.size(); i++) {
			if(check[v[i]]) continue;
			answer.push_back(v[i]);
			check[v[i]] = true;
		}
		v.clear();
	}
	
	// OUTPUT
	sort(answer.begin(), answer.end());
	int answerSize = answer.size();
	printf("%d\n", answerSize);
	for(int i=0; i<answerSize; i++) printf("%d\n", answer[i]);
	
	return 0;
}



