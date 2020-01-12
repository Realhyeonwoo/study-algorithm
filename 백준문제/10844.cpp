/*
	n자리인 계단수의 갯수 
	d[n][k] : n자리이며 끝자리가 k인 자연수 (k: 0~9)
	
	d[n][k] = d[n-1][k-1] + d[n-1][k+1] (k= 1~8)
			= d[n-1][8] (k = 9)
			= d[n-1][1] (k = 0)
*/

#include<iostream>
#define mod 1000000000
using namespace std; 

int d[101][10]; 
int main(void) {
	int n; 
	cin >> n; 
	
	for(int i=1; i<=9; i++) d[1][i] = 1; 
	
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=9; j++) {
			if(j == 0){
				d[i][j] = d[i-1][1] % mod;
			} else if(j == 9) {
				d[i][j] = d[i-1][8] % mod;
			} else {
				d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % mod; 
			}
		}
	}
	
	long long ans = 0;
	for(int i=0; i<=9; i++) {
		ans += d[n][i];
	}
	
	ans %= mod; 
	
	cout << ans << endl; 
	return 0; 
}
