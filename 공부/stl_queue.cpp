#include<iostream>
#include<queue>
using namespace std;

int main(void) {
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	
	cout << q.size() << '\n';
	if(q.empty()) cout << "Q is empty\n";
	else cout << "Q is not empty\n";
	
	q.pop();
	cout << q.front() << "\n";
	cout << q.back() << "\n";
	
	q.push(40);
	q.pop();
	cout << q.front() << "\n";
	return 0;
}
