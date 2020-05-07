#include<iostream> 
#include<string>
using namespace std;

int main(void) {
	string str = "abc";
	string temp = str.substr(1, 3);
	cout << temp << endl;
	cout << str.substr(2, 10) << endl;
	cout << str << endl;
	return 0;
}
