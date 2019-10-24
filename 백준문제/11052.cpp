#include<iostream>
using namespace std;

int d[1001];
int a[1001];

int max(int a, int b) {
	return a>b ? a : b; 
}

int main(void) {
	int n; 
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
		
	for(int i=1; i<=n; i++) {	
		for(int j=1; j<=i; j++) {
			d[i] = max(d[i], d[i-j]+a[j]); 
		}
	}

	cout << d[n] << endl;
	
	return 0; 
}
