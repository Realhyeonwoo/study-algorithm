#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int T, N, size;
set<string> arr;
string str[20000];

bool compare(string a, string b) {
	if(a.size() == b.size()) {
		return a < b;		
	} else {
		return a.size() < b.size();
	}
}

int main(void) {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// RESET
		arr.clear();
		
		// INPUT
		scanf("%d", &N);
		string temp;
		for(int i=0; i<N; i++) {
			cin >> temp;
			arr.insert(temp);
		}
		
		// SIMULATION
		int idx = 0;
		set<string>::iterator iter;
		for(iter=arr.begin(); iter!=arr.end(); iter++) {
			str[idx++] = *iter;
		}
		sort(str, str+idx, compare);
		
		// OUTPUT
		printf("#%d\n", tc);
		for(int i=0; i<idx; i++) {
			cout << str[i] << "\n";
		}
	}
	return 0;
}


