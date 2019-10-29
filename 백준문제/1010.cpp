#include<iostream>
using namespace std; 

int main(void) {
	int t; 
	cin >> t; 
	while(t--) {
		int n, m;
		cin >> n >> m; 
		
		int sum = 1; 
		for(int i=m; i>=(m-n+1); i--) {
			sum *= i; 
		}
		
		int sum2 = 1; 		
		for(int i=n; i>=1; i--) {
			sum2 *= i; 
		}
		
		sum = sum2 / sum; 
		
		cout << sum << endl;		
	}
	
	return 0; 
}
