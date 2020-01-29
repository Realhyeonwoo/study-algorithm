#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
vector<int> V[101];
bool visited[101] = {false, };
int bfs(int start) {
	memset(visited, false, sizeof(visited));
	int count = 0; 
	visited[start] = true;
	for(int i=0; i<V[start].size(); i++) {
		visited[V[start][i]] = true;
		count++;
		printf("%d(1) ", V[start][i] );
	}
	
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(i == start || !visited[i]) continue;
		q.push(i);
	}
	
	int plus = 2;
	while(!q.empty()) {
		queue<int> tq;
		while(!q.empty()) {
			tq.push(q.front());
			q.pop();
		}
		
		while(!tq.empty()) {
			int x = tq.front();
			tq.pop();
			for(int i=0; i<V[x].size(); i++) {
				if(!visited[V[x][i]]) {
					visited[V[x][i]] = true;
					count += plus;
					if(V[x][i] != start) {
						q.push(V[x][i]);
					}
					printf("%d(%d) ", V[x][i], plus);
				}		
			}
		}
		
		int flag = false;
		for(int i=1; i<=n; i++) {
			if(!visited[i]) {
				flag = true;
				break;
			}
		}
		
		if(!flag) {
			while(!q.empty()) {
				q.pop();
			}
		}
		
		plus++;
	}
	
	return count;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		V[num1].push_back(num2);
		V[num2].push_back(num1);
	}
	
	int index = 1; 
	int min = 99999999;
	for(int i=1; i<=n ; i++) {
		int res = bfs(i);	
		printf("\n%d¹ø³ëµå: %d\n\n",  i, res);
		if(min > res) {
			min = res;
			index = i;
		}
	}
	
	printf("%d\n", index);
	return 0;
}
