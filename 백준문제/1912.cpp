/*
	d[i]: a[i]�� ������ �ִ� ������  
		- a[i-1]�� ������ �������� ���� => d[i-1] + a[i]
		- ���ο� => a[i]  
	 
*/

#include<iostream>
using namespace std; 

int d[100001]; 
int a[100001]; 

int max(int a, int b) {
	return a > b ? a : b; 
}

int main(void) {
	int n; 
	cin >> n; 
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	
	for(int i=1; i<=n; i++) {
		d[i] = max(d[i-1] + a[i], a[i]); 
	}
	
	int ans = d[1];
	for(int i=2; i<=n; i++) {
		if(ans < d[i]) ans=d[i];
	}
	
	cout << ans << endl; 
	return 0; 
}
