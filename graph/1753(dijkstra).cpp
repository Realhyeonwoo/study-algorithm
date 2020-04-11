#include<iostream>
#include<vector>
#include<queue>

#define MAX 20000
#define INF 987654321
using namespace std;

int V, E, Start;
vector<pair<int, int> > v[MAX + 1];
int d[MAX + 1];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(d[start], start));
//	pq.push(make_pair(start, d[start]));
	
	while(!pq.empty()) {
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if(distance > d[cur]) continue;
		for(int i=0; i<v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDistance = v[cur][i].second + distance;
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-d[next], next));
			}
		}
	}
}

int main(void) {
	for(int i=1; i<=MAX; i++) d[i] = INF;
	
	scanf("%d %d", &V, &E);
	scanf("%d", &Start);
	int a, b, c;
	for(int i=0; i<E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	
	dijkstra(Start);
	
	// OUTPUT
	for(int i=1; i<=V; i++) {
		if(d[i] == INF) {
			printf("INF\n");
		} else {
			printf("%d\n", d[i]);
		}
	}
	
	return 0;
}
