#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void) {
	map<string, int> m;
	
	m.insert(make_pair("woo", 10));
	m.insert(make_pair("hyeon", 20));
	
	
	// find
	cout << "name: "<< m.find("woo")->first << endl;
	cout << "count: " << m.find("woo")->second << endl;
	cout << "count: "<< m.count("woo") << endl;
	
	cout << "name: "<< m.count("aswoo") << endl;
//	cout << "count: " << m.find("aswoo")->second << endl;
	cout <<endl;
	
	// size
	cout << "size: " << m.size() << endl;
	
	map<string, int>::iterator iter;
	
	// ���ٹ� 1 
	for(iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ", " << iter->second << endl;
	}
	cout << endl;
	
	
	// �� ���� �� ���ٹ� 2 
	m["woo"] = 123;
	for(iter = m.begin(); iter != m.end(); iter++) {
		cout << (*iter).first << ", " << (*iter).second << endl;
	}
	cout << endl;
	
	// erase
	m.erase("woo");
	for(iter = m.begin(); iter != m.end(); iter++) {
		cout << (*iter).first << ", " << (*iter).second << endl;
	}
	cout << m.size() << endl;
	cout << endl;
	
	
	// �Ѱ� ��� 
	cout << "���°�:  " << m["woodf"] << endl;
	cout << endl;
	
	
	
	return 0;
}
