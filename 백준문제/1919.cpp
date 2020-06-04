#include<iostream>
#include<string>
using namespace std;

int arr[2][26];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	string str1, str2;
	cin >> str1 >> str2;
	
	for(int i=0; i<str1.length(); i++) arr[0][str1[i] - 'a']++;
	for(int i=0; i<str2.length(); i++) arr[1][str2[i] - 'a']++;
	
	int ans = 0;
	for(int i=0; i<26; i++) {
		ans += abs(arr[0][i] - arr[1][i]);
	}
	
	cout << ans << "\n";
	
	return 0;
}
