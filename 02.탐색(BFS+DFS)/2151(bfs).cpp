#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int> > v[10001];
int d[10001];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(start, 0));
	
	while(!pq.empty()) {
		int cur = pq.top().first;
		int direction = -pq.top().second;
		pq.pop();
		
		if(direction > d[cur]) continue;
		
		for(int i=0; i<v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDirection = direction + v[cur][i].second;
			
			if(nextDirection < d[next]) {
				d[next] = nextDirection;
				pq.push(make_pair(next, -nextDirection));
			}
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d", &n);
	int a, b, dis;
	for(int i=1; i<n; i++) {
		scanf("%d %d %d", &a, &b, &dis);
		v[a].push_back(make_pair(b, dis));
		v[b].push_back(make_pair(a, dis));
	}
	
	// SIMULATION
	int answer = -987654321;
	for(int r=1; r<=n; r++) {
		for(int i=1; i<=n; i++) d[i] = 987654321;

		dijkstra(r);
		
		for(int i=1; i<=n; i++) {
			answer = max(answer, d[i]);
		}
	}

	// OUTPUT
	printf("%d\n", answer);
	
	return 0;
}
