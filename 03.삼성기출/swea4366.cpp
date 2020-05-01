#include<iostream> 
#include<string>
#include<vector>
using namespace std;

string str1, str2;

int changeNum(string s, int n) {
	int num = 0, sum = 0;
	for(int i=s.length()-1; i>=0; i--) {
		num = s[i] - '0';
		for(int j=i; j<s.length()-1; j++) {
				num *= n;
		}
		sum += num;
	}
	return sum;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		str1.clear();
		str2.clear();
		
		// INPUT
		cin >> str1 >> str2;
		
		// SIMULATION
		vector<int> num1, num2;
		// 2진수 
		for(int i=0; i<str1.length(); i++) {
			str1[i] = (str1[i] == '0') ? '1' : '0';
			num1.push_back(changeNum(str1, 2));
			str1[i] = (str1[i] == '0') ? '1' : '0';
		}
		// 3진수
		for(int i=0; i<str2.length(); i++) {
			char origin = str2[i];
			
			if(str2[i] == '0') {
				str2[i] = '1';
				num2.push_back(changeNum(str2, 3));
				str2[i] = '2';
				num2.push_back(changeNum(str2, 3));
			} else if(str2[i] == '1') {
				str2[i] = '0';
				num2.push_back(changeNum(str2, 3));
				str2[i] = '2';
				num2.push_back(changeNum(str2, 3));
			} else if(str2[i] == '2') {
				str2[i] = '0';
				num2.push_back(changeNum(str2, 3));
				str2[i] = '1';
				num2.push_back(changeNum(str2, 3));
			}
			str2[i] = origin;
		}
		
		// OUTPUT
		int answer = 0;
		for(int i=0; i<num1.size(); i++) {
			for(int j=0; j<num2.size(); j++) {
				if(num1[i] == num2[j]) {
					answer = num1[i];
					break;
				}
			}
		}
		printf("#%d %d\n", tc, answer);
	}
	return 0;
}
