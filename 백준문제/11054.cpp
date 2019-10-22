#include<iostream>
using namespace std; 

int d1[1001];
int d2[1001];
int a[1001];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i=1; i<=n; i++) {
		d1[i] = 1;
		for(int j=1; j<i; j++) {
			if(a[j] < a[i] && d1[i] > d1[j] + 1){
				d1[i] = d1[j] + 1; 
			}
		}
	}
	
	for(int i=n-1; i>0; i++) {
		d2[i] = 1; 
		for(int j=i+1; j<n; j++) {
			if(a[j] < a[i] && d2[i] < d2[j] + 1) {
				d2[i] = d2[j] + 1; 
			}
		}
	}
	
	int ans = 0; 
	for(int i=1; i<=n; i++) {
		if(ans < d1[i] + d2[i] -1) {
			ans = d1[i] + d2[i] -1;
		}
	}
	
	printf("%d\n", ans); 
	return 0; 
}
