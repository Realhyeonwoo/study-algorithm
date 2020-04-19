#include<iostream>
#include<queue>
using namespace std;

int N, K;
int answer;
bool visited[100001];

void bfs(int start) {
	queue<int> q;
	
	if(start == K) return;
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()) {
		int q_size = q.size();
		
		answer++;
		
		for(int i=0; i<q_size; i++) {
			int now = q.front();
			q.pop();
			
			if(now-1 == K || now+1 == K || now*2 == K) return;
			
			if(now-1 >=0 && now-1 <= 100000 && !visited[now-1]) {
				visited[now-1] = true;
				q.push(now-1);	
			}
			if(now+1 >=0 && now+1 <= 100000 && !visited[now+1]){
				visited[now+1] = true;
			 	q.push(now+1);	
			}
			if(now*2 >=0 && now*2 <= 100000 && !visited[now*2]){
				visited[now*2] = true;
				q.push(now*2);	
			} 
		}
		
	}
}

int main(void) {
	scanf("%d %d", &N, &K);
	
	bfs(N);
	
	printf("%d\n", answer);
	return 0;
}
