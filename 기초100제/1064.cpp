#include<stdio.h>

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c); 
	
	if(a > b) {
		printf("%d", b > c ? c : b );
	} else {
		printf("%d", a > c ? c : a );
	}

	return 0; 
}
