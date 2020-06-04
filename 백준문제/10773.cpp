#include<iostream>
#include<stack>
using namespace std;

int K;
stack<int> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> K;
	int num;
	while(K--) {
		cin >> num;
		if(num == 0) {
			if(!S.empty()) S.pop();
		} else {
			S.push(num);
		}
	}
	
	int sum = 0;
	while(!S.empty()) {
		sum += S.top();
		S.pop();
	}
	
	cout << sum << "\n";
	return 0;
}
