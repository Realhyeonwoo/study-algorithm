#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
vector<int> heavier[100], lighter[100]; // 1 ~ 99
bool hVisited[100], lVisited[100];

int Hdfs(int start) {
	int result = 1;
	for(int i=0; i<heavier[start].size(); i++) {
		int next = heavier[start][i];
		if(hVisited[next]) continue;
		hVisited[next] = true;
		result += Hdfs(next);
	}
	
	return result;
}

int Ldfs(int start) {
	int result = 1;
	for(int i=0; i<lighter[start].size(); i++) {
		int next = lighter[start][i];
		if(lVisited[next]) continue;
		lVisited[next] = true;
		result += Ldfs(next);
	}
	
	return result;
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) {
		int m1, m2;
		scanf("%d %d", &m1, &m2); 
		
		heavier[m2].push_back(m1);
		lighter[m1].push_back(m2);
	}
	
	// SIMULATION
	int count = 0; 
	for(int i=1; i<=N; i++)	{
		memset(hVisited, false, sizeof(hVisited));
		memset(lVisited, false, sizeof(lVisited));
		hVisited[i] = true;
		lVisited[i] = true;
		
		if(Hdfs(i) > (N+1)/2) count++;
		if(Ldfs(i) > (N+1)/2) count++;
	}
	
	// OUTPUT
	printf("%d\n", count);
	return 0;
}
