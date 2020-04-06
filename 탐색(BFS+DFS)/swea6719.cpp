#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, K;
vector<pair<int, bool> > v;

double answer = 0;

bool compare(pair<int, bool> a, pair<int, bool> b) {
	return a.first < b.first;
}
int main(void) {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		answer = 0.0;
		v.clear();
		
		// INPUT
		scanf("%d %d", &N, &K);
		int num;
		for(int i=1; i<=N; i++) {
			scanf("%d", &num);
			v.push_back(make_pair(num, false));
		}
		sort(v.begin(), v.end(), compare);
		
		// SIMULATION
		int count = 0;
		bool flag = false;
		bool flag2 = false;
		while(1) {
			if(flag || flag2) break;
			flag2 = false;
			for(int i=0; i<v.size(); i++) {
				if(count == K) {
					flag = true;
					break;
				}
				if(!v[i].second && v[i].first > answer) {
					flag2 = true;
					answer = (answer + v[i].first) / 2;
				}
				count++;
			}
		}
		
		// OUTPUT
		printf("#%d %f", tc, answer);
		
	}
	return 0;
}
