/*
	50m 당 한병  / 맥주 최대 20병 => 최대 1000m 이동 가능
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int T, n;
vector<pair<int, int> > v;
vector<int> node[102];
bool visited[102];

void dfs(int start) {
	visited[start] = true;
	
	for(int i=0; i<node[start].size(); i++) {
		int next = node[start][i];
		if(visited[next]) continue;
		
		dfs(next);
	}
}

int main(void) {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		memset(visited, false, sizeof(visited));
		v.clear();
		for(int i=0; i<102; i++) {
			node[i].clear();
		}
		
		// INPUT
		scanf("%d", &n);
		int y, x;
		for(int i=0; i<n+2; i++) {
			scanf("%d %d", &y, &x);
			v.push_back(make_pair(y, x));
		}
		
		// SIMULATION
		for(int i=0; i<n+2; i++) {
			for(int j=i+1; j<n+2; j++) {
				int distance = abs(v[i].first - v[j].first) + abs(v[i].second + v[j].second);
				if(distance <= 1000) {
					node[i].push_back(j);
					node[j].push_back(i);
				}
			}
		}
		
		dfs(0);
		
		// OUTPUT
		printf("%s\n", visited[n+1] ? "happy" : "sad");
	}
	
	return 0;
}
