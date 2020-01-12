#include<iostream>
using namespace std; 

long long d[101]; 

int main(void) {
	d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 2; d[5] = 2;
	d[6] = 3; d[7] = 4; d[8] = 5; d[9] = 7; d[10] = 9;
	
	int t; 
	cin >> t; 
	while(t--) {
		int n; 
		cin >> n; 
		
		for(int i=11; i<=n; i++){
			d[i] = d[i-2] + d[i-3];
		}
		
		cout << d[n] << endl; 
	}
}


