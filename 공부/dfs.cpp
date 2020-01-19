#include<iostream>
#include<vector>
using namespace std;

int visited[8];
vector<int> a[8];

void dfs(int start) {
	if(visited[start]) return;
	visited[start] = true;
	printf("%d ", start);
	for(int i=0; i<a[start].size(); i++) {
		int y = a[start][i];
		dfs(y);
	}
}

int main(void) {
	// 1과 2를 연결 
	a[1].push_back(2);
	a[2].push_back(1);
	// 1과 3을 연결 
	a[1].push_back(3);
	a[3].push_back(1);
	// 2와 3을 연결 
	a[2].push_back(3);
	a[3].push_back(2);
	// 2와 4를 연결 
	a[2].push_back(4);
	a[4].push_back(2);
	// 2와 5를 연결 
	a[2].push_back(5);
	a[5].push_back(2);
	// 3과 6을 연결 
	a[3].push_back(6);
	a[6].push_back(3);
	// 3과 7을 연결 
	a[3].push_back(7);
	a[7].push_back(3);
	// 4와 5를 연결 
	a[4].push_back(5);
	a[5].push_back(4);
	// 6과 7을 연결 
	a[6].push_back(7);
	a[7].push_back(6);
	

	dfs(1);
	return 0; 
}
