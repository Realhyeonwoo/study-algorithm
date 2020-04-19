#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, k;
vector<int> node_first[401];
vector<int> node_last[401];
bool visited[401];

int first_bfs(int n1, int n2) {
	queue<int> q;
	visited[n1] = true;
	q.push(n1);
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if(cur == n2) return -1;
		
		for(int i=0; i<node_first[cur].size(); i++) {
			int next = node_first[cur][i];
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
	return 0;
}

int last_bfs(int n1, int n2) {
	queue<int> q;
	visited[n1] = true;
	q.push(n1);
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if(cur == n2) return 1;
		
		for(int i=0; i<node_last[cur].size(); i++) {
			int next = node_last[cur][i];
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
	return 0;
}

int main(void) {
	scanf("%d %d", &n, &k);
	int n1, n2;
	for(int i=0; i<k; i++) {
		scanf("%d %d", &n1, &n2);
		node_first[n1].push_back(n2);
		node_last[n2].push_back(n1);
	}
	int s;
	scanf("%d", &s);
	for(int i=0; i<s; i++) {
		memset(visited, false, sizeof(visited));
		
		scanf("%d %d", &n1, &n2);
		
		int check = first_bfs(n1, n2);
		if(check == -1) {
			printf("%d\n", check);
			continue;
		}
		memset(visited, false, sizeof(visited));
		check = last_bfs(n1, n2);
		if(check == 1) {
			printf("%d\n", check);
			continue;
		}
		printf("0\n");
	}
	
	return 0; 
}
