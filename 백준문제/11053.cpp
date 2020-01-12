/*
	d[i]: 마지막 숫자가 i번째인 a[i]인 가장 긴 증가 수열 
	
	a[i] 전에 숫자 a[j] 
		- j < i
		- a[j] < a[i]
	
	d[i] = d[j] + 1; 
*/

#include<iostream>
using namespace std; 

int d[1001];
int a[1001];

int main(void) {
	int n; 
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i]; 
	}
	
	for(int i=1; i<=n; i++) {
		d[i] = 1; 
		for(int j=1; j<i; j++) {
			if(a[j] < a[i] && d[i] < d[j] + 1){
				d[i] = d[j] + 1; 
			}
		}
	}
	
	int ans = d[1];
	for(int i=2; i<=n; i++) {
		if(ans < d[i]) ans = d[i]; 
	}
	
	cout << ans << endl; 
	return 0; 
}
