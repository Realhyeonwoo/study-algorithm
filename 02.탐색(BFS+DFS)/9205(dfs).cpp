#include<iostream>
#include<vector>
#include<cstring>
#include<cstring>
#include<utility>
#include<cmath>
using namespace std;

int t;
int n;
vector<int> node[102];
bool visited[102];

void go_dfs(int now) {
	visited[now] = true;
	
	for(int i=0; i<node[now].size(); i++) {
		int next = node[now][i];
		if(visited[next]) continue;
		go_dfs(next);
	}
}

int main(void) {
	scanf("%d", &t);
	for(int test_case=1; test_case<=t; test_case++) {
		// RESET
		memset(visited, false, sizeof(visited));
		for(int i=0; i<102; i++) {
			node[i].clear();	
		}
		
		
		// INPUT
		scanf("%d", &n);
		vector<pair<int, int> > coord;
		for(int i=0; i<n+2; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			coord.push_back(make_pair(y, x));
		}
		for(int i=0; i<n+2; i++) {
			for(int j=i+1; j<n+2; j++) {
				int distance = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
				if(distance <= 1000) {
					node[i].push_back(j);
					node[j].push_back(i);
				}
			}
		}
		
		// SIMULATION
		go_dfs(0);
		
		// OUTPUT
		if(visited[n+1]) {
			printf("happy\n");
		} else {
			printf("sad\n");
		}
	}
	
	return 0;
}
