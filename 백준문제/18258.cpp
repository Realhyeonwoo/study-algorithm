#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N;
queue<int> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	string op;
	while(N--) {
		cin >> op;
		
		if(op == "push") {
			int num; cin >> num;
			Q.push(num);
		} else if(op == "pop"){
			if(Q.empty()) cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		} else if(op == "size"){
			cout << Q.size() << '\n';
		} else if(op == "empty"){
			if(Q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		} else if(op == "front"){
			if(Q.empty()) cout << -1 << '\n';
			else cout << Q.front() << '\n';
		} else if(op == "back"){
			if(Q.empty()) cout << -1 << '\n';
			else cout << Q.back() << '\n';
		}
	}
	
	return 0;
}
