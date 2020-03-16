#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
vector<pair<int, int> > v[10001];
bool visited[10001];
int maxCost, Start, End;

bool bfs(int cost) {
	queue<int> q;
	visited[Start] = true;
	q.push(Start);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		if(x == End) return true;
		
		for(int i=0; i<v[x].size(); i++) {
			pair<int, int> cur = v[x][i];
			int nx = cur.first;
			int nCost = cur.second;
			
			if(!visited[nx] && cost <= nCost) {
				visited[nx] = true;
				q.push(nx);
			}
		}
	}
	return false;
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &M); 
	int a, b, c;
	for(int i=0; i<M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
		maxCost = max(maxCost, c);
	}
	scanf("%d %d", &Start, &End);
	
	// SIMULATION
	int low = 0, high = maxCost;
	while(low <= high) {
		memset(visited, false, sizeof(visited));
		int mid = (low + high) / 2;
		if(bfs(mid)) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	// OUTPUT
	printf("%d\n", high);
	
	return 0;
}
