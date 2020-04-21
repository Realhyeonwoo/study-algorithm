#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	for(int i=0; i<str.length(); i++) {
		printf("%c => %s\n", str[i], isdigit(str[i]) != 0 ? "숫자입니다." : "숫자가 아닙니다.");
	}
	return 0;
}

