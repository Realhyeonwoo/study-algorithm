#include<iostream>
#include<string>
#include<list>
using namespace std;

string str;
list<char> L;
int M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;
	for(int i=0; i<str.length(); i++) L.push_back(str[i]);
	list<char>::iterator cursor = L.end();
	
	cin >> M;
	while(M--) {
		char op; cin >> op;
		
		if(op == 'P') {
			 char word; cin >> word;
			 L.insert(cursor, word);
		} else if(op == 'L') {
			if(cursor != L.begin()) cursor--;
		} else if(op == 'D') {
			if(cursor != L.end()) cursor++;
		} else if(op == 'B'){ 
			if(cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}
	
	for(list<char>::iterator it = L.begin(); it != L.end(); it++) {
		cout << *it;
	}
	return 0;
}
