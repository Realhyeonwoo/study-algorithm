#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int K, V, E;
vector<int> node[20001];
int check[20001]; // -1 or 1;

bool dfs(int now, int c) {
	check[now] = c;
	
	for(int i=0; i<node[now].size(); i++) {
		int next = node[now][i];
		
		if(check[next] != 0 && check[now] == check[next]) return false;
		if(check[next] == 0 && !dfs(next, -c)) return false;
	}
	
	return true;
}

int main(void) {
	scanf("%d", &K);
	for(int test_case=1; test_case<=K; test_case++) {
		// RESET
		memset(check, 0, sizeof(check));		
		for(int i=0; i<20001; i++) {
			node[i].clear();
		}
		
		// INPUT
		scanf("%d %d", &V, &E);
		int n1, n2;
        for (int i = 0; i < E; i++){
            scanf("%d %d", &n1, &n2);
            node[n1].push_back(n2);
            node[n2].push_back(n1);
        }
		
		// SIMULATION
		bool flag = true;
		for(int i=1; i<=V; i++) {
			if(check[i] != 0) continue;
			if(!dfs(i, 1)) {
				flag = false;
				break;
			}
		}
		
		// OUTPUT
		if(flag) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;
}
