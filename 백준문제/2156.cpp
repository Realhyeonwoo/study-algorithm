#include<iostream>
using namespace std;

int d[10001][3];
int a[10001];

int max(int n1, int n2) {
	return n1>=n2 ? n1 : n2; 
}

int main(void) {
	int n; 
	cin >> n; 
	for(int i=1; i<=n; i++) cin >> a[i]; 
	
	d[1][0] = 0;  d[1][1] = a[1]; d[1][2] = a[1];
	for(int i=2; i<=n; i++) {
		for(int j=0; j<3; j++) {
			d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
			d[i][1] = d[i-1][0] + a[i];
			d[i][2] = d[i-1][1] + a[i]; 
		}
	}
	int ans = max(d[n][0], max(d[n][1], d[n][2]));
	cout << ans << endl;
	
	return 0; 
}
