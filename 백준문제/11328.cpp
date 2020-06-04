#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int alpha[2][26];
string str1, str2;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for(int tc=1; tc<=T; tc++)	 {
		// INIT
		for(int i=0; i<2; i++) {
			fill(alpha[i], alpha[i]+26, 0);	
		}
		
		// INPUT
		cin >> str1 >> str2;
		
		// SIMULATION
		if(str1.length() != str2.length()) {
			cout << "Impossible" << "\n";
			continue;
		}
		
		for(int i=0; i<str1.length(); i++) alpha[0][str1[i] - 'a']++;
		for(int i=0; i<str2.length(); i++) alpha[1][str2[i] - 'a']++;
		
		// OUTPUT
		bool isFlag = false;
		for(int i=0; i<26; i++) {
			if(alpha[0][i] != alpha[1][i]) {
				isFlag = true;
				break;
			}
		}
		if(isFlag) cout << "Impossible" << "\n";
		else cout << "Possible" << "\n";
	}
	
	return 0;
}
