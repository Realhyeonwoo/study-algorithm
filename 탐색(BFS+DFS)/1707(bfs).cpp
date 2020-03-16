	#include<iostream>
	#include<vector>
	#include<queue>
	#include<cstring>
	using namespace std;
	
	int T, V, E;
	vector<int> node[20001];
	bool visited[20001];
	int value[20001];
	
	bool check_bfs(int start, int flag) {
		queue<int> q;
		visited[start] = true;
		value[start] = flag;
		q.push(start);
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
				
			for(int i=0; i<node[x].size(); i++) {
				int nx = node[x][i];
				if(visited[nx]) {
					if(value[x] == value[nx]) return false;
					continue;
				}
				value[nx] = -value[x];
				visited[nx] = true;
				q.push(nx);
			}
		}
		
		return true;	
	}
	
	int main(void) {
		scanf("%d", &T);
		for(int test_case=1; test_case<=T; test_case++) {
			// RESET
			memset(visited, false, sizeof(visited));
			memset(value, 0, sizeof(value));
			for(int i=1; i<=20000; i++) {
				node[i].clear();
			}
			
			// INPUT
			scanf("%d %d", &V, &E); 
			int n1, n2;
			for(int i=0; i<E; i++) {
				scanf("%d %d", &n1, &n2);
				node[n1].push_back(n2);
				node[n2].push_back(n1);
			}
			
			// SIMULATION
			bool answer = true;
			for(int i=1; i<=V; i++) {
				if(!visited[i]) {
					answer &= check_bfs(i, 1);		
				}
			}
			
			// OUTPUT
			if(answer) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
		
		return 0;
	}
