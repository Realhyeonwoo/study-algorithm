#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1) {
		string str;
		getline(cin, str);
		
		if(str.length() == 1 && str[0] == '.') break;
	
		stack<char> Stk;
		bool isError = false;
		for(int i=0; i<str.length(); i++) {
			if(str[i] == '(' || str[i] == '[' ) {
				Stk.push(str[i]);
			} else if(str[i] == ')' || str[i] == ']') {
				if(Stk.empty()) {
					isError = true;
					break;
				} else if(str[i] == ')' && Stk.top() != '(') {
					isError = true;
					break;
				} else if(str[i] == ']' && Stk.top() != '[') {
					isError = true;
					break;
				} else {
					Stk.pop();
				}
			}
		}
		if(!Stk.empty()) isError = true;
		
		cout << (!isError ? "yes" : "no") << '\n';
	}
	
	
	return 0;
}
