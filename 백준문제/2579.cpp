/*
	d[n]: n개의 계단에서 얻을 수 있는 총 점수의 최댓값 

	연속 0번 =>    x o 
	연속 1번 =>  x o o

	d[n][0] = max(d[n-2][0], d[n-2][1]) + a[n]
	d[n][1] = max(d[n-3][0], d[n-3][1]) + a[n-1] + a[n]
	d[n][1] = d[n-1][0] + a[n]
	max(d[n][0], d[n][1])
*/

#include<iostream>
using namespace std; 

int d[301][2];
int a[301];

int max(int a, int b) {
	return a>b ? a : b; 
}

int main(void) {
	int n;
	cin >> n; 
	for(int i=1; i<=n; i++) {
		cin >> a[i]; 
	}
	
	for(int i=1; i<=n; i++) {
		d[i][0] = max(d[i-2][0], d[i-2][1]) + a[i];
		d[i][1] = d[i-1][0] + a[i];
	}
	
	cout << max(d[n][0], d[n][1]) << endl; 
	
	return 0; 
}
