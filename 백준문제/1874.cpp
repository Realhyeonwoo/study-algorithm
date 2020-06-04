#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n, now = 1;
stack<int> S;
string ans = "";

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int num;
	for(int i=1; i<=n; i++) {
		cin >> num;
		while(now <= num) {
			S.push(now++);
			ans += "+";
		}
		
		if(!S.empty() && S.top() == num) {
			S.pop();
			ans += '-';
			continue;
		} else {
			cout << "NO" << "\n";
			ans = "";
			break;
		}
	}
		for(int i=0; i<ans.length(); i++) {
			cout << ans[i] << "\n";
		}
	return 0;
}
