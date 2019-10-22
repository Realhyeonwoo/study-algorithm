#include<iostream>
using namespace std; 

int d[301][3];
int a[301]; 

int max(int n, int m) {
	return n>m ? n : m; 
}

int main(void) {
	int n;
	cin >> n; 
	for(int i=1; i<=n; i++) cin >> a[i];
	
	for(int i=1; i<=n; i++) {
		d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
		d[i][2] = d[i-1][1] + a[i];
	}
	
	int ans = max(d[n][1], d[n][2]);
	cout << ans << endl;
	return 0; 
}
