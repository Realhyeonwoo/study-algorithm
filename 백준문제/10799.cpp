#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	
	int sum = 0;
	stack<char> Stk;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == '(') {
			Stk.push(str[i]);
		} else {
			if(Stk.top() == str[i-1]) {
				Stk.pop();	
				sum += Stk.size(); 
			} else {
				Stk.pop();
				sum += 1;
			}
			
		}
	}
	
	cout << sum << "\n";
	return 0;
}
