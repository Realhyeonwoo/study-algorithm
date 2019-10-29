#include<iostream>
#define mod 10007
using namespace std; 
int d[1001];

int main(void) {
	int n;
	cin >> n; 
	
	d[0] = 1; d[1] = 1;
	for(int i=2; i<=n; i++) {
		d[i] = (d[i-1] + d[i-2]) % mod; 
	}
	
	cout << d[n] << endl;
	return 0; 
}
