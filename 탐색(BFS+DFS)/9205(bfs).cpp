#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdlib>
using namespace std;

int t, n;
vector<pair<int, int> > v;
bool visited[102];

bool dist(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) + abs(y1-y2)) <= 1000 ? true : false;
}

int main(void) {
	scanf("%d", &t);
	for(int test_case=1; test_case<=t; test_case++) {
		// INPUT
		scanf("%d", &n);
		int x, y;
		for(int i=0; i<n+2; i++) {
			scanf("%d %d", &x, &y);
			v.push_back(make_pair(x, y));
		}
		
		queue<int> q;
		q.push(0);
		visited[0] = true;
		
		bool isFind = false;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			
			if(v[now].first == v[n+1].first && v[now].second == v[n+1].second) {
				isFind = true;
				break;
			}
			
			for(int i=1; i<n+2; i++) {
				if(!visited[i] && dist(v[now].first, v[now].second, v[i].first, v[i].second)) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
		
		if(isFind) {
			printf("happy\n");
		} else {
			printf("sad\n");
		}
	}
	
	return 0;
}
