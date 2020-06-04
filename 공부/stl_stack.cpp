#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	stack<int> s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	
	cout << s.size() << "\n";
	
	if(s.empty()) cout << "S is empty\n";
	else cout << "S is not empty\n";
	
	s.pop();
	cout << s.top() << "\n";
	s.pop();
	cout << s.top() << "\n";
	s.pop();
	if(s.empty()) cout << "S is empty\n";
	else cout << "S is not empty\n";
	
	return 0;
}
