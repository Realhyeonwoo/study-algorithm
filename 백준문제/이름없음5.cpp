#include<iostream>
using namespace std;

int d[501][501];
int a[501][501];

int max(int x, int y) {
	return x>y ? x : y; 
}

int main(void) {
		int n;
		cin >> n; 
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++){
				cin >> a[i][j]; 
			}
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				if(j==1) {
					d[i][j] = d[i-1][j] + a[i][j];
				} else if(j == i) {
					d[i][j] = d[i-1][j-1] + a[i][j];
				} else {
					d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
				}
			}
		}
		
		int ans = d[n][1];
		for(int i=2; i<=n; i++){
			if(d[n][i] > ans) ans = d[n][i]; 
		}
		
		cout << ans << endl; 
	return 0; 
}
