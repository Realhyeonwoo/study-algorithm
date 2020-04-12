#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 8
using namespace std;

vector<pair<int, int> > node[MAX];
bool visited[MAX];

void init() {
	node[1].push_back(make_pair(7, 12));
	node[1].push_back(make_pair(4, 28));
	node[1].push_back(make_pair(2, 67));
	node[1].push_back(make_pair(5, 17));
	
	node[2].push_back(make_pair(4, 24));
	node[2].push_back(make_pair(5, 62));
	node[2].push_back(make_pair(1, 67));
	
	node[3].push_back(make_pair(5, 20));
	node[3].push_back(make_pair(6, 37));
	
	node[4].push_back(make_pair(7, 13));
	node[4].push_back(make_pair(1, 28));
	node[4].push_back(make_pair(2, 24));
	
	node[5].push_back(make_pair(6, 45));
	node[5].push_back(make_pair(7, 73));
	node[5].push_back(make_pair(1, 17));
	node[5].push_back(make_pair(2, 62));
	node[5].push_back(make_pair(3, 20));
	
	node[6].push_back(make_pair(3, 37));
	node[6].push_back(make_pair(5, 45));
	
	node[7].push_back(make_pair(1, 12));
	node[7].push_back(make_pair(4, 13));
	node[7].push_back(make_pair(5, 73));
}

int main(void) { 
	init();
	
	priority_queue<pair<int, int> > pq;
	for(int i=0; i<node[1].size(); i++) {
		pq.push(make_pair(-node[1][i].second, node[1][i].first));
	}
	
	visited[1] = true;
	int sum = 0;
	while(!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		
		if(visited[cur]) continue;
		visited[cur] = true;
		sum += distance;
		for(int i=0; i<node[cur][i].size(); i++) {
			int next = node[cur][i].first;
			int nextDistance = node[cur][i].second;
			if(!visited[next]) {
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
	
	printf("%d\n", sum);
	return 0;
}
