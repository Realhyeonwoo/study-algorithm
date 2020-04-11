#include<iostream>
#include<vector>
#include<queue>

#define MAX 10001
using namespace std;

int V, E;
vector<pair<int, int> > v[MAX];
bool visited[MAX];

int main(void) {
	// INPUT
	scanf("%d %d", &V, &E);
	int a, b, c;
	for(int i=0; i<E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	
	// SIMULATION
	int answer = 0;
	priority_queue<pair<int, int> > pq;
	visited[1] = true;
	for(int i=0; i<v[1].size(); i++) {
		pq.push(make_pair(-v[1][i].second, v[1][i].first));
	}
	
	while(!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;	
		pq.pop();
		
		if(visited[cur]) continue;
		visited[cur] = true;
		answer += distance;
		
		for(int i=0; i<v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextDistance = v[cur][i].second;
			if(!visited[next]) pq.push(make_pair(-nextDistance, next));
		}
	}
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
