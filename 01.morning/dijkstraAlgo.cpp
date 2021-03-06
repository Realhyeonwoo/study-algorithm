#include<iostream>
#include<queue>
#include<vector>

#define MAX 7
#define INF 987675321
using namespace std;

vector<pair<int, int> > a[MAX];
int d[MAX];

void init() {
	for(int i=1; i<MAX; i++) d[i] = INF;
	
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
}

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(d[start], start));
	
	while(!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if(distance > d[cur]) continue;
		for(int i=0; i<a[cur].size(); i++) {
			int next = a[cur][i].first;
			int nextDistance = distance + a[cur][i].second;
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-d[next], next));
			}
		}
	}
}

int main(void) {
	init();
	dijkstra(1);
	for(int i=1; i<MAX; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}
