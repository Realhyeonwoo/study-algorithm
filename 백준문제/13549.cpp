#include<iostream>
#include<queue>
#define MAX 100001
#define INF 987564321
using namespace std;

int N, K, Answer = INF;
int visited[MAX];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// INIT
	fill(visited, visited+MAX, INF);
	
	// INPUT	
	cin >> N >> K;
	
	// SIMULATION
	visited[N] = 0;
	queue<int> Q;
	Q.push(N);
	
	while(!Q.empty()) {
		int now = Q.front();
		Q.pop();
			
		cout << now << ' ';
		
		if(now == K) {
			Answer = visited[K];
			break;
		}
		
		if(now+1 < MAX && visited[now+1] > visited[now] + 1) {
			visited[now+1] = visited[now] + 1;
			Q.push(now + 1);
		}
		
		if(now-1 >= 0 && visited[now-1] > visited[now] + 1) {
			visited[now-1] = visited[now] + 1;
			Q.push(now - 1);
		}
		
		if(now*2 < MAX && visited[now*2] > visited[now]) {
			visited[now*2] = visited[now];
			Q.push(now*2);
		}
	}
	
	// OUTPUT
	cout << Answer;
	
	return 0;
}
