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

	// ����  
	cout << s.count("a") << endl;
	cout << s.size() << endl;
	
	// ��ü ��ȸ  
	set<string>::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << endl;
	}
	
	// ���� �˻� 
	iter = s.find("a");
	if(iter != s.end()) {
		cout << *iter << " : ����" << endl;
	} else {
		cout << "�������� ����" << endl;
	}
	
	// ����  
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
