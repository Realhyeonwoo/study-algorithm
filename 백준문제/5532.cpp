#include<iostream>
using namespace std;

int main(void) {
	int L, A, B, C, D;
	scanf("%d", &L); // 총 방학 일 
	scanf("%d", &A); // 국어 총 페이지 
	scanf("%d", &B); // 수학 총 페이지 
	scanf("%d", &C); // 국어 최대 페이지 
	scanf("%d", &D); // 수학 최대 페이지 
	
	for(int i=1; i<=L; i++) {
		if(A > 0) A -= C;
		if(B > 0) B -= D;
		if(A<=0 && B<=0) {
			printf("%d", L - i);
			break;
		}		
	}
}
