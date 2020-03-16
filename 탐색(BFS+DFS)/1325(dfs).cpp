#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> computer[10001];
bool visited[10001];
int cnt;
vector<int> answer; 
int hackedCom[10001];
int maxV = -9999;
int N, M; 

void hacking_dfs(int com) {
	visited[com] = true;
	cnt++; 
	
	for(int i=0; i<computer[com].size(); i++) {
		int next = computer[com][i];
		if(visited[next]) continue;
		hacking_dfs(next);
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M); 
	for(int i=0; i<M; i++) {
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		computer[c2].push_back(c1);
	}
	
	// SIMULATION
	for(int i=1; i<=N; i++) {
		cnt = 0; 
		memset(visited, false, sizeof(visited));
		
		hacking_dfs(i);
		
		hackedCom[i] = cnt;
		if(maxV <= cnt) {
			maxV = cnt;
		}
	}
	
	for(int i=1; i<=N; i++) {
		if(maxV == hackedCom[i]) {
			answer.push_back(i);
		}
	}
	
	// OUTPUT
	sort(answer.begin(), answer.end());
	for(int i=0; i<answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	
	return 0;
}
