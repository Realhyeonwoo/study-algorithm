/*
	d[n]: n�ڸ� ��ģ���� ���� 
	
	- 0 ���� ����X
	- 11 �������� X 
	
	1�ڸ� : 1 (1��)
	2�ڸ� : 10 (1��)
	3�ڸ� : 101, 100 (2��)
	
	n�ڸ� : 
		(n-1)�ڸ� + 0   => d[n-1] 
		(n-2)�ڸ� + 01   => d[n-2] + 01 
	d[n] = d[n-1] + d[n-2]
*/

#include<iostream>
using namespace std; 

long long int d[91];

int main(void) {
	int n;
	cin >> n; 
	
	d[1] = d[2] = 1;
	for(int i=3; i<=n; i++) {
		d[i] = d[i-1] + d[i-2];
	}
	
	cout << d[n] << endl; 
	return 0; 
}
