#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

int n, arr[MAX], Answer;
vector<int> v;
bool visited[MAX];

int bfs(int start, int end) {
	queue<int> Q;
	vector<int> temp;
	Q.push(arr[start]);
	visited[start] = true;
	int sum = 1;
	temp.push_back(start);
	
	while(!Q.empty()) {
		int now = Q.front();
		Q.pop();
		temp.push_back(now);
		
		if(visited[now] && now == end) {
			for(int i=0; i<temp.size(); i++) v.push_back(temp[i]);
			return sum;	
		}
		else if(visited[now] && now != end) {
			return 0;	
		}
		
		visited[now] = true;
		Q.push(arr[now]);
		
		sum++;
	}
	
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	for(int tc=1; tc<=T; tc++) {
		// INIT
		fill(visited, visited + MAX, false);
		fill(arr, arr + MAX, 0);
		Answer = 0;
		
		// INPUT
		cin >> n;
		int num;
		for(int i=1; i<=n; i++){
			cin >> num;
			arr[i] = num;
//			if(i == num) {
//				visited[i] = true;
//				Answer++;
//			}
		}
		
		// SIMULATION
		for(int i=1; i<=n; i++) {
			fill(visited, visited + MAX, false);
			for(int i=0; i<v.size(); i++) visited[v[i]] = true;
			Answer += bfs(i, i);
//			cout << i << ": " << Answer << '\n';
		}
		
		// OUTPUT
		cout << n - Answer << '\n';
	}
	
	return 0;
}
