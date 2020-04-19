#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct Water {
	int a, b, c;
};

int A, B, C;
bool visited[201][201][201];
vector<int> answer;

void bfs(int a, int b, int c) {
	queue<Water> q;
	Water w = {a, b, c};
	q.push(w);
	
	while(!q.empty()) {
		int ca = q.front().a;
		int cb = q.front().b;
		int cc = q.front().c;
		q.pop();
		
		if(visited[ca][cb][cc]) continue;
		visited[ca][cb][cc] = true;
		
		if(ca == 0) answer.push_back(cc);
		
		// A -> B
		if(ca+cb > B) {
			w = {ca+cb - B, B, cc};
			q.push(w);
		} else {
			w = {0, ca+cb, cc};
			q.push(w);
		}
		// A -> C
		if(ca+cc > C) {
			w = {ca+cc - C, cb, C};
			q.push(w);
		} else {
			w = {0, cb, ca+cc};
			q.push(w);
		}
		// B -> A
		if(cb + ca > A) {
			w = {A, cb + ca - A, cc};
			q.push(w);
		} else {
			w = {cb+ca, 0, cc};
			q.push(w);
		}
		// B -> C
		if(cb + cc > C) {
			w = {ca, cb+cc-C, C};
			q.push(w);
		} else {
			w = {ca, 0, cb+cc};
			q.push(w);
		}
		// C -> A
		if(cc + ca > A) {
			w = {A, cb, cc + ca -  A};
			q.push(w);
		} else {
			w = {cc+ca, cb, 0};
			q.push(w);
		}
		// C -> B
		if(cc + cb > B) {
			w = {ca, B, cc+cb-B};
			q.push(w);
		} else {
			w = {ca, cc+cb, 0};
			q.push(w);
		}
	}
	
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &A, &B, &C);
	
	// SIMULATION
	bfs(0, 0, C);
	
	// OUTPUT
	sort(answer.begin(), answer.end());
	for(int i=0; i<answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	
	return 0;
}
