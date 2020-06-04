#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int num[10];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	string str;
	cin >> str;
	
	for(int i=0; i<str.length(); i++) {
		num[str[i] - '0']++;
	}
	
	if(num[6] != num[9]) {
		int temp = (num[6] + num[9]) / 2;
		
		if((num[6] + num[9]) % 2 == 0) {
			num[6] = temp;
		} else {
			num[6] = temp + 1;	
		}
		num[9] = temp;
		
	} 
	
	cout << *max_element(num, num+10) << "\n";
	return 0;
}
