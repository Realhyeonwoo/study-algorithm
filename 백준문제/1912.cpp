#include<iostream>
using namespace std;

int d[100001];
int a[100001]; 

int main(void) {
	int n; 
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		cin >> a[i]; 
	}
	
	for(int i=1; i<=n; i++) {
		d[i] = a[i]; 
		if(d[i] < d[i-1] + a[i]) {
			d[i] = d[i-1] + a[i]; 
		}
	}
	
	int ans = d[1];
	for(int i=2; i<=n; i++) {
		if(ans < d[i]) ans = d[i];
	}
	
	cout << ans << endl;
	return 0; 
}
