#include<iostream>
#include<list>
using namespace std;

int main(void) {
	list<int> l;
	
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);
	
	l.pop_back();
	
	l.push_front(4);
	l.push_front(3);
	l.push_front(1);
	l.push_front(0);
	
	l.pop_front();
	
	cout << "list front value : " << l.front() << "\n";
	cout << "list end value : " << l.back() << "\n";
	
	cout << "list size : " << l.size() << "\n";
	
	cout << "Is it empty? : " << (l.empty() ? "TRUE" : "FALSE") << "\n";
	
//	#1
	cout << "\n\n";
	for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n\n";
	
//	#2
	list<int>::iterator t = l.begin();
	cout << "iterator: " << *t << "\n";
	t++;
	cout << "iterator: " << *t << "\n";
	l.insert(t, 2);
	for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n\n";
	
//	#3
	t--;
	cout << "iterator: " << *t << "\n";
	t--;
	cout << "iterator: " << *t << "\n";
	l.erase(t);
	
	for(list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}
