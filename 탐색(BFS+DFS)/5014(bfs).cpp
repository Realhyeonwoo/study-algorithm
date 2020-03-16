#include<iostream>
#include<queue>
using namespace std;

int F, S, G, U, D;
// 총 층수(F), 시작위치(S), 도착 점(G), 위로(U), 아래로(D)
 bool visited[1000001];

//int bfs() {
//	queue<pair<int, int> > q;
//	visited[S] = true;
//	q.push(make_pair(S, 0));
//	
//	while(!q.empty()) {
//		int x = q.front().first;
//		int cnt = q.front().second;
//		q.pop();
//		
//		if(x == G) return cnt;
//		
//		int nx;
//		// U
//		nx = x + U;
//		if(nx <= F && !visited[nx]) {
//			visited[nx] = true;
//			q.push(make_pair(nx, cnt + 1));
//		}
//		// D
//		nx = x - D;
//		if(nx > 0 && !visited[nx]) {
//			visited[nx] = true;
//			q.push(make_pair(nx, cnt + 1));
//		}
//	}
//	return -1;
//} 

int bfs() {
	queue<int> q;
	visited[S] = true;
	q.push(S);
	
	int count = 0; 
	while(!q.empty()) {
		int qSize = q.size(); 
		
		for(int i=0; i<qSize; i++) {
			int x = q.front();
			q.pop();
			
			if(x == G) return count; 
		
			int nx;
			// U
			nx = x + U;
			if(nx<=F && !visited[nx]) {
				visited[nx]	= true;
				q.push(nx);
			}
			// D
			nx = x - D;
			if(nx>=1 && !visited[nx]) {
				visited[nx] = true;
				q.push(nx);
			}			
		}
		if(q.size() != 0)count++;
	}
	return -1;
}

int main(void) {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	int answer = bfs();
	
	if(answer == -1) {
		printf("use the stairs\n");
	} else {
		printf("%d\n", answer);
	}
	return 0;
}
