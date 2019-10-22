#include<iostream>
#include<algorithm>
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
			if(a[j] < a[i] && d[i] < d[j]+a[i]) {
				d[i] = d[j] + a[i]; 
			}
		}
	}
	
	int ans = d[1];
	for(int i=2; i<=n; i++){
		if(ans < d[i]) ans = d[i]; 
	}
	cout << ans << endl;
	return 0; 
}
