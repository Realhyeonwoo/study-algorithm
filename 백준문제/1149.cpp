#include<iostream>
using namespace std;

int d[1001][3]; // r:0, g:1, b:2
int a[1001][3];

int min(int x, int y) {
	return x>y ? y : x; 
}
int main(void) {
		int n;
		cin >> n; 
		
		for(int i=1; i<=n; i++) {
			for(int j=0; j<3; j++) {
				cin >> a[i][j];
			}
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=0; j<3; j++) {
				d[i][0] = min(d[i-1][1], d[i-1][2]) + a[i][0];
				d[i][1] = min(d[i-1][0], d[i-1][2]) + a[i][1];
				d[i][2] = min(d[i-1][0], d[i-1][1]) + a[i][2];
			}
		}
		
		int ans = min(d[n][0], min(d[n][1], d[n][2])); 
		cout << ans << endl; 
	
	return 0; 
}
