#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

#define MAX 20
using namespace std;

int N, L, Answer;
vector<pair<int, int> > v;
bool visited[MAX];

void dfs(int idx, int score, int cal) {
	if(cal > L) return;
	else {
		Answer = max(Answer, score);
	}
	
	for(int i=idx; i<N; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		score += v[i].first;
		cal += v[i].second;
		
		dfs(i, score, cal);
		
		visited[i] = false;
		score -= v[i].first;
		cal -= v[i].second;
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		v.clear();
		memset(visited, false, sizeof(visited));
		Answer = 0;
		
		// INPUT
		scanf("%d %d", &N, &L);
		int score, cal;
		for(int i=0; i<N; i++) {
			scanf("%d %d", &score, &cal);
			v.push_back(make_pair(score, cal));
		}
		
		// SIMULATION
		dfs(0, 0, 0);
		
		// OUTPUT
		printf("#%d %d\n", tc, Answer);
	}
	return 0;
}
