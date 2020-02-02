#include<iostream>
#include<vector>
using namespace std;

int n, m;
int child, target;
int count = 0; 
vector<int> relation[101];
bool visited[101] = {false, };

void dfs(int start, int cnt) {
	if(start == target) {
		count = cnt;
		return;
	}
	
	visited[start] = true;
	
	for(int i=0; i<relation[start].size(); i++) {
		int next = relation[start][i];
		
		if(visited[next]) continue;
		
		visited[next] = true;
		dfs(next, cnt + 1);
	}
}

int main(void) {
	scanf("%d", &n);
	scanf("%d %d", &child, &target);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		relation[num1].push_back(num2);
		relation[num2].push_back(num1);
	}
	
	dfs(child, 0);
	
	if(count == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", count);
	}
	
	return 0;
}
