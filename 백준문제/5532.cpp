#include<iostream>
using namespace std;

int main(void) {
	int L, A, B, C, D;
	scanf("%d", &L); // �� ���� �� 
	scanf("%d", &A); // ���� �� ������ 
	scanf("%d", &B); // ���� �� ������ 
	scanf("%d", &C); // ���� �ִ� ������ 
	scanf("%d", &D); // ���� �ִ� ������ 
	
	for(int i=1; i<=L; i++) {
		if(A > 0) A -= C;
		if(B > 0) B -= D;
		if(A<=0 && B<=0) {
			printf("%d", L - i);
			break;
		}		
	}
}
