#include<iostream>
using namespace std; 

int d[31];

int main(void) {
	int n; 
	cin >> n;
	
	d[0] = 1; 
	for(int i=2; i<=n; i++) {
		d[i] = d[i-2];
		for(int j=i-2; j>=0; j-=2) {
			d[i] += 2*d[j];
		}
	}
	
	cout << d[n] << endl;
	return 0; 
}
