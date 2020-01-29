#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n;
vector<int> node[101];
int res[101][101] = { 0, };
bool visited[101] = { false, };

void bfs(int start) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(start);
	
	while(!q.empty()) {
		int x = q.front(); 
		q.pop();

		for(int i=0; i<node[x].size(); i++) {
			int y= node[x][i];
			
			if(visited[y]) continue;
			visited[y] = true;
			q.push(y);
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(visited[i]) {
			res[start][i] = 1;
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int num;
			scanf("%d", &num);
			if(num == 1) {
				node[i].push_back(j);	
			}
		}
	}
		
	for(int i=1; i<=n; i++) {
		bfs(i);
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0; 
}
