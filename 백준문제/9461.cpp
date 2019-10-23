#include<iostream>
using namespace std;

int d[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main(void) {
	int t;
	cin >> t; 
	while(t--) {
		int n;
		cin >> n;
				
		for(int i=11; i<=n; i++) {
			d[i] = d[i-1] + d[i-5];
		}
		
		cout << d[n] << endl;
	}
	return 0; 
}
