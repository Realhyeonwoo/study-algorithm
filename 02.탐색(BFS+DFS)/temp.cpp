#include<iostream>
#include<set>
#include<string>
using namespace std;

void setInit(void) {
	set<string> s;
	
	s.insert("a");
	s.insert("a");
	s.insert("b"); 
	s.insert("c");

	// 갯수  
	cout << s.count("a") << endl;
	cout << s.size() << endl;
	
	// 전체 순회  
	set<string>::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << endl;
	}
	
	// 존재 검사 
	iter = s.find("a");
	if(iter != s.end()) {
		cout << *iter << " : 존재" << endl;
	} else {
		cout << "존재하지 않음" << endl;
	}
	
	// 삭제  
	iter = s.find("b");
	s.erase(iter); 
	for(iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << endl;
	}
} 

void setPair(void) {
	string name[5] = {"a", "b", "c", "d", "a"};
	set<pair<string, int> > s;
	
	s.insert(make_pair("hyeonwoo", 1));
	
	set<pair<string, int> >::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++) {
		cout << (*iter).first << " " << (*iter).second << endl;
	}
}

int main(void) {
	
//	setInit();
	
	setPair();
	return 0;
}
