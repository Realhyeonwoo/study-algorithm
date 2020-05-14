#include<iostream>
#include<vector>
#include<queue>

#define MAX 32001
using namespace std;

int N, M, inDegree[MAX];
vector<int> a[MAX];

void topologySort(void) {
	int result[MAX];
	queue<int> q;
	
	for(int i=1; i<=N; i++) {
		if(inDegree[i] == 0) {
			q.push(i);
			printf("%d ", i);
		}
	}
	printf("\n");
	
	for(int i=1; i<=N; i++) {
		int x = q.front();
		q.pop();
		result[i] = x;
		for(int i=0; i<a[x].size(); i++) {
			int y = a[x][i];
			if(--inDegree[y] == 0) q.push(y);
		}
	}
	for(int i=1; i<=N; i++) printf("%d ", result[i]);
}

int main(void) {
	scanf("%d %d", &N, &M);
	int num1, num2;
	for(int i=0; i<M; i++) {
		scanf("%d %d", &num1, &num2);
		a[num1].push_back(num2);
		inDegree[num2]++;
	}
	topologySort(); 
	
	return 0;
}
