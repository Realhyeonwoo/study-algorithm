#include<iostream>
#include<queue>
using namespace std;

int  A, B, N, M;
int map[100001]; // 0 ~ 100000
bool visited[100001];
int answer; 

void bfs(int start) {
	queue<int> q;
	visited[start] = true;
	q.push(start);
	
	while(!q.empty() ) {
		int qSize = q.size();
		
		answer++;
		for(int i=0; i<qSize; i++) {
			int now = q.front();
			q.pop();
			
			if(now-1>=0 && !visited[now-1]) {
				if(now-1 == M) return;
				visited[now-1] = true;
				q.push(now-1);
			}
			if(now-A>=0 && !visited[now-A]) {
				if(now-A == M) return;
				visited[now-A] = true;
				q.push(now-A);
			}
			if(now-B>=0 && !visited[now-B]) {
				if(now-B == M) return;
				visited[now-B] = true;
				q.push(now-B);
			}
			if(now+1<=100000 && !visited[now+1]) {
				if(now+1 == M) return;
				visited[now+1] = true;
				q.push(now+1);
			}
			if(now+A<=100000 && !visited[now+A]) {
				if(now+A == M) return;
				visited[now+A] = true;
				q.push(now+A);
			}
			if(now+B<=100000 && !visited[now+B]) {
				if(now+B == M) return;
				visited[now+B] = true;
				q.push(now+B);
			}
			if(now*A<=100000 && !visited[now*A]) {
				if(now*A == M) return;
				visited[now*A] = true;
				q.push(now*A);
			}
			if(now*B<=100000 && !visited[now*B]) {
				if(now*B == M) return;
				visited[now*B] = true;
				q.push(now*B);
			}
		}
	}
}
int main(void) {
	scanf("%d %d %d %d", &A, &B, &N, &M);
	bfs(N);
	printf("%d\n", answer);
	return 0;
}
