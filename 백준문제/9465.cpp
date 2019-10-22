#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int d[100001][3];
int a[3][100001];

int max(int num1, int num2) {
	return num1>num2 ? num1 : num2;
}

int max3(int num1, int num2, int num3) {
	if(num1 >= num2 && num1 >= num3) {
		return num1; 
	} else if(num2 >= num1 && num2 >= num3) {
		return num2;
	} else if(num3 >= num1 && num3 >= num2) {
		return num3;
	}
}

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n; 
		
		for(int i=1; i<=2; i++) {
			for(int j=1; j<=n; j++) {
				cin >> a[i][j]; 
			}
		}
		
		for(int i=1; i<=n; i++) {
			d[i][0] = max3(d[i-1][0], d[i-1][1], d[i-1][2]);
			d[i][1] = max(d[i-1][0], d[i-1][2]) + a[1][i];
			d[i][2] = max(d[i-1][0], d[i-1][1]) + a[2][i];
		}
		
		cout << max3(d[n][0], d[n][1], d[n][2]) << endl; 
	}
	return 0; 
}
