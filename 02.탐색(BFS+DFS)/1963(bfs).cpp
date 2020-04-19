#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int T, startNum, endNum;
bool visited[10000]; // 0 ~ 9999;

bool isPrimality(int num) {
	for(int i=2; i<num; i++) {
		if(num % i == 0) return false;
	}
	return true;
}

int bfs(int number) {
	queue<int> q;
	visited[number] = true;
	q.push(number);
	
	int answer = 0;
	while(!q.empty()) {
		int qSize = q.size();
		for(int i=0; i<qSize; i++) {
			int x = q.front();
			q.pop();
			
			if(x == endNum) return answer;
			
			int temp = x;
			int d1 = temp / 1000; temp %= 1000;
			int d2 = temp / 100; temp %= 100;
			int d3 = temp / 10; temp %= 10;
			int d4 = temp;
			int nx;
			
			// 1000의 자리 변경 
			for(int i=1; i<10; i++) {
				if(d1 == i) continue;
				int nx = i*1000 + x % 1000;
				if(!visited[nx] && isPrimality(nx)) {
					visited[nx] = true;
					q.push(nx);
				}
			}
			// 100의 자리 변경
			for(int i=0; i<10; i++) {
				if(d2 == i) continue;
				int nx = x - d2*100 + i*100;
				if(!visited[nx] && isPrimality(nx)) {
					visited[nx] = true;
					q.push(nx);
				}
			}
			// 10의 자리 변경
			for(int i=0; i<10; i++) {
				if(d3 == i) continue;
				int nx = x - d3*10 + i*10;
				if(!visited[nx] && isPrimality(nx)) {
					visited[nx] = true;
					q.push(nx);
				}
			}
			// 1의 자리 변경
			for(int i=0; i<10; i++) {
				if(d4 == i) continue;
				int nx = x - d4 + i;
				if(!visited[nx] && isPrimality(nx)) {
					visited[nx] = true;
					q.push(nx);
				}
			}
		}
		answer++;
	}
	return -1;	
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		memset(visited, false, sizeof(visited));
		// INPUT
		scanf("%d %d", &startNum, &endNum);
		// SIMULATION
		int result = bfs(startNum);
		// OUTPUT
		if(result == -1) {
			printf("Impossible\n");
		} else {
			printf("%d\n", result);
		}
	}
	
	return 0;
}
