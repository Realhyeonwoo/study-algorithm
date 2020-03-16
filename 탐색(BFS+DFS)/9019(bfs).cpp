#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int T, A, B;
bool visited[10000];

string bfs(int a) {
	queue<pair<int, string> > q;
	visited[a] = true;
	q.push(make_pair(a, ""));
	
	while(!q.empty()) {
		int x = q.front().first;
		string s = q.front().second;
		q.pop();
		
		if(x == B) return s;
		
		// D
		int nx = x*2;
		if(nx > 9999) nx %= 10000;
		if(!visited[nx]) {
			visited[nx] = true;
			q.push(make_pair(nx, s+"D"));
		}
		// S
		nx = x - 1;
		if(nx < 0) nx = 9999;
		if(!visited[nx]) {
			visited[nx] = true;
			q.push(make_pair(nx, s+"S"));
		}
		// L
		nx = (x%1000)*10 + (x/1000);
		if(!visited[nx]) {
			visited[nx] = true;
			q.push(make_pair(nx, s+"L"));
		}
		// R
		nx = (x % 10) * 1000 + (x/10);
		if(!visited[nx]) {
			visited[nx] = true;
			q.push(make_pair(nx, s+"R"));
		}
	}
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		memset(visited, false, sizeof(visited));
		
		// INPUT
		scanf("%d %d", &A, &B);
		
		// SIMULATION
		string answer = bfs(A);
		
		// OUTPUT
		cout << answer << "\n";
	}
	return 0;
}
