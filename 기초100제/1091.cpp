#include<stdio.h>

int main(void) {
	long long int a, d, m, n;
	scanf("%lld %lld %lld %lld", &a, &d, &m, &n); 
	
	for(int i=1; i<n; i++) {
		a *= d; 
		a += m; 
	}
	
	printf("%lld", a); 
	return 0; 
}
