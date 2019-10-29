/*
7
3   8
8   1   0
2   7   4   4
4   5   2   6   5
 
d[n][k]: n줄 k번째 까지의 최댓값 

	
	- if(k == 1) d[i][k] = d[i-1][k]+ d[i][k]
	- d[i][k] = max(d[i-1][k] + d[i][k], d[i-1][k-1] + d[i][k])
	- if(k == n) d[i][k] = d[i-1][k-1] + d[i][k]
	
	ans = max(d[n][1], d[n][2], ....., d[n][n])
*/

#include<iostream>
using namespace std; 

int d[501][501]; 

int max(int a, int b) {
	return a>b ? a : b;
}

int main(void) {
	int n;
	cin >> n; 
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			cin >> d[i][j]; 
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(j == 1) {
				d[i][j] += d[i-1][j];
			} else if(i == j) {
				d[i][j] += d[i-1][j-1];
			} else {
				d[i][j] = max(d[i][j] + d[i-1][j], d[i][j] + d[i-1][j-1]); 
			}
		}
	}
	
	int ans = d[n][1];
	for(int i=2; i<=n; i++) {
		if(ans < d[n][i]) {
			ans = d[n][i];
		}
	}
	
	cout << ans << endl; 
	return 0; 
}
