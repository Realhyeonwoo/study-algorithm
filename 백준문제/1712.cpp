/*
	A(고저비용) =  임대료 + 재산세 + 보험료 + 급여 등
	B(1대당) = 재료비 + 인건비  
	C = 노트북 가격  
	
	A + B * n < C * n 
	A < (C - B) * n 
	A / (C - B) < n 
*/

#include<stdio.h>

int main(void) {
	long long A, B, C; 
	scanf("%lld %lld %lld", &A, &B, &C); 
	
	if(C-B <= 0) {
		printf("-1"); 
		return 0; 
	}
	
	long long num = A / (C - B) + 1;
	
	printf("%lld\n", num); 
	
	return 0; 
}
