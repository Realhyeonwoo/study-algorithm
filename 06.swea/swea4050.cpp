#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, sum, discount;
vector<int> v;

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		v.clear();
		sum = 0;
		discount = 0;
			
		// INPUT
		scanf("%d", &N);
		int n;
		for(int i=0; i<N; i++) {
			scanf("%d", &n);
			v.push_back(n);
			sum += n;
		}
		
		// SIMULATION
		sort(v.begin(), v.end(), greater<int>());
			int idx = 0;
			while(1) {
				vector<int> temp;
				if(idx+3 > v.size()) break;
				for(int j=idx; j<idx+3; j++) temp.push_back(v[j]);
				sort(temp.begin(), temp.end());
				discount += temp[0];
				idx += 3;
			}
		
		// OUTPUT
		printf("#%d %d\n", tc, sum - discount);
	}
	return 0 ;
}
