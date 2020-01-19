#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int visited[8];
vector<int> a[8];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		
		for(int i=0; i<a[x].size(); i++) {
			int y = a[x][i];
			if(!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
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
	
//	for(int i=0; i<8; i++){
//		for(int j=0; j<a[i].size(); j++){
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
	bfs(1);
	return 0; 
}
