/*
	d[n]: n을 1, 2, 3 의 합으로 나타내는 경우의 수  
	n = (n-1) + 1
	n = (n-2) + 2
	n = (n-3) + 3
	d[n] = d[n-1] + d[n-2] + d[n-3]
*/

#include<iostream>
using namespace std; 

int d[11];
int main(void) {
	int t;
	cin >> t; 
	while(t--) {
		int n;
		cin >> n; 
		
		d[1] = 1; d[2] = 2; d[3] = 4;
		for(int i=4; i<=n; i++) {
			d[i] = d[i-1] + d[i-2] + d[i-3];
		}
		
		cout << d[n] << endl; 
	}
	return 0; 
}
