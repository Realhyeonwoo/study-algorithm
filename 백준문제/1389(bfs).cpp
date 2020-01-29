#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int> node[101];
int dis[101];

int bfs(int start) {
	memset(dis, 0, sizeof(dis));
	int sum = 0;	
	queue<int> q;
	q.push(start);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		sum += dis[x];
		
		for(int i=0; i<node[x].size(); i++) {
			int y = node[x][i];
			if(y == start || dis[y] != 0) continue;
			dis[y] = dis[x] + 1;
			q.push(y);
		}
	}
	
	return sum;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for(int j=0; j<m; j++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		node[num1].push_back(num2);
		node[num2].push_back(num1);
	}
	
	int min = 1e9;
	int minIdx = 1;
	for(int i=1; i<=n; i++) {
		int res = bfs(i);
		if(min > res) {
			min = res;
			minIdx = i;
		}
	}
	printf("%d\n", minIdx);
	
	return 0; 
}
