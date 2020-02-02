#include<iostream>
#include<queue>
using namespace std;

int n, m;
int x, y;
int count = 0; 
vector<int> relation[101];
int visited[101] = {0, };

void bfs(int child) {
	queue<int> q;
	q.push(child);
//	visited[child] = 0;
	
	while(!q.empty()) {
		int target = q.front();
		q.pop();
		
		if(y == target) {
			break;
		}
		
		for(int i=0; i<relation[target].size() ; i++) {
			int next = relation[target][i];
			if(visited[next] != 0) continue;
			visited[next] = visited[target] + 1;
			q.push(next);
		}
		
	}
}

int main(void) {
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		relation[num1].push_back(num2);
		relation[num2].push_back(num1);
	}
	
	bfs(x);
	
	if(visited[y] == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", visited[y]);
	}
	
	
	return 0;
}
