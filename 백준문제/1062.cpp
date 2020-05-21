#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, K, Answer;
bool alpha[26];
vector<string> v;

bool canRead(string str) {
	for(int i=0; i<str.length(); i++) {
		if(!alpha[str[i] - 'a']) return false;
	}
	return true;
}

void dfs(int start, int cnt) {
	if(cnt == K-5) {
		int sum = 0;
		for(int i=0; i<v.size(); i++) {
			if(canRead(v[i])) sum++;
		}
		Answer = max(Answer, sum);
		return; 
	}
	
	for(int i=start; i<26; i++) {
		if(alpha[i]) continue;
		alpha[i] = true;
		dfs(i, cnt + 1);
		alpha[i] = false;
	}
}

int main(void) {
	// INPUT
	scanf("%d %d", &N, &K);
	
	string str;
	for(int i=0; i<N; i++) {
		cin >> str;
		v.push_back(str);
	}
	
	// SIMULATION
	if(K < 5) {
		printf("%d\n", Answer);
		return 0;
	}
	
	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;
	
	dfs(0, 0);
		
	// OUTPUT
	printf("%d\n", Answer);
	return 0;
}
