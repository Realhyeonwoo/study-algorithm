/*
	d[n]: n자리 이친수의 갯수 
	
	- 0 으로 시작X
	- 11 연속으로 X 
	
	1자리 : 1 (1개)
	2자리 : 10 (1개)
	3자리 : 101, 100 (2개)
	
	n자리 : 
		(n-1)자리 + 0   => d[n-1] 
		(n-2)자리 + 01   => d[n-2] + 01 
	d[n] = d[n-1] + d[n-2]
*/

#include<iostream>
using namespace std; 

long long int d[91];

int main(void) {
	int n;
	cin >> n; 
	
	d[1] = d[2] = 1;
	for(int i=3; i<=n; i++) {
		d[i] = d[i-1] + d[i-2];
	}
	
	cout << d[n] << endl; 
	return 0; 
}
