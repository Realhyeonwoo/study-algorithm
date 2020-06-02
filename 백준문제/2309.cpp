#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num[9];
bool visited[9];
vector<int> v;

void dfs(int start, int cnt) {
	if(cnt == 7 && v.size() == 0) {
		int sum = 0;
		for(int i=0; i<9; i++) {
			if(visited[i]) {
				sum += num[i];
				v.push_back(num[i]);
			}
		}
		
		if(sum == 100) sort(v.begin(), v.end());
		else v.clear();
		
		return;
	}
	
	for(int i=start; i<9; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		dfs(i, cnt+1);
		if(v.size() != 0) return;
		visited[i] = false;
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// INPUT
	for(int i=0; i<9; i++) cin >> num[i];
	
	// SIMULATION
	dfs(0, 0);
	
	// OUTPUT
	for(int i=0; i<v.size(); i++) cout << v[i] << " ";
	
	return 0;
}
