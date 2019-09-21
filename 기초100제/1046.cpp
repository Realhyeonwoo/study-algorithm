#include<stdio.h>

int main(void) {
	long long int a, b, c; 
	scanf("%lld %lld %lld", &a, &b, &c); 
	
	int sum = a+b+c; 
	printf("%d\n", sum);
	printf("%.1f\n", sum / 3.0);
	
	return 0; 
}
