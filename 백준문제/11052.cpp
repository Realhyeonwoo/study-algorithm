/*
	n���� ī�带 ���� 
	a[1] ~ a[n] ���� ����ִ� ī���� �ݾ� 	
	
	d[n] : ī�� n�� �� �� �ִ� �ݾ�
	
	�������� k�� ¥�� ���� �� �� => d[n] = max(d[n], d[n-k] + a[k]) 
	d[3] d[2]+a[1] d[1]+a[2]
	
	d[2] d[1] + a[1]
*/

#include<iostream>
using namespace std; 

int d[1001];
int a[1001];

int main(void) {
	int n; 
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i]; 
	
	for(int i=1; i<=n; i++) {
		d[i] = a[i]; 
		for(int j=1; j<i; j++) {
			if(d[i] < d[i-j] + a[j]) {
				d[i] = d[i-j] + a[j]; 
			}
		}
	}
	
	cout << d[n] << endl; 
	return 0; 
}
