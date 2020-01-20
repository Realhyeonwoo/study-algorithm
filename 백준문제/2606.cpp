#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> arr[101];
bool visited[101] = {false, };

void Bfs(int start, int n) {
	int count = 0; 
	queue<int> q;
	q.push(start);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		visited[x] = true;
		count += 1;
		
			for(int j=0; j<arr[x].size(); j++) {
				int y = arr[x][j];
				if(!visited[y]) {
					q.push(y);
					visited[y] = true;
				}
			}
		
	}
	printf("%d\n", count-1);
}

int main(void) {
	int n;
	scanf("%d", &n); // 컴퓨터 번호 1 ~ n 
	int m;
	scanf("%d", &m) ; // 연결 라인 수 m개
	for(int i=0; i<m; i++)  {
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		arr[c1].push_back(c2);
		arr[c2].push_back(c1);
	}
	
	Bfs(1, n);
	
	return 0; 
}
