#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

int N, K;
deque<char> dq;
int size = 0;
vector<string> v[7];

int changeNum(char c) {
	if('0'<=c && c<='9') return c - '0';
	else if(c == 'A') return 10;
	else if(c == 'B') return 11;
	else if(c == 'C') return 12;
	else if(c == 'D') return 13;
	else if(c == 'E') return 14;
	else if(c == 'F') return 15;
}

void StoreValue(int idx) {
	for (deque<int>::size_type i = 0; i < dq.size(); i+=size){
	  	string sum = "";
	  	for(int j=i; j<i+size; j++) {
			sum += dq[j];	
		}
		v[idx].push_back(sum);
	}
}

void doRotate(void) {
	int temp = dq.back();
	dq.pop_back();
	dq.push_front(temp);
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		for(int i=0; i<7; i++) v[i].clear();
		dq.clear();
		
		// INPUT
		scanf("%d %d", &N, &K);
		char n;
		for(int i=0; i<N; i++) {
			scanf(" %c", &n);
			dq.push_back(n);
		}
		
		// SIMULATION
		size = N/4;
		for(int r=0; r<size; r++) {
			StoreValue(r);
			doRotate();
		}
		
		// OUTPUT
		set<string> answer;
		for(int i=0; i<size; i++) {
			for(int j=0; j<v[i].size(); j++) {
				answer.insert(v[i][j]);
			}
		}
		
		int index = 1;
		set<string>::iterator iter;

		vector<int> output;
		for(iter=answer.begin(); iter!=answer.end(); iter++) {
			string res = *iter;
			int mul = size, sum = 0;
			for(int i=0; i<res.length(); i++) {
				int num = changeNum(res[i]);
				for(int j=1; j<mul; j++) {
					num *= 16;
				}
				sum += num;
				mul--;
			}
			output.push_back(sum);
		}
		
		sort(output.begin(), output.end(), greater<int>());

		printf("#%d %d\n", tc, output[K-1]);
	}
	return 0;
}
