/*
	A(�������) =  �Ӵ�� + ��꼼 + ����� + �޿� ��
	B(1���) = ���� + �ΰǺ�  
	C = ��Ʈ�� ����  
	
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
