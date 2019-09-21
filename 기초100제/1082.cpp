#include<stdio.h>

int main(void) {
	int num; 
	scanf("%X", &num);
	
	for(int i=1; i<=15; i++) {
		printf("%X*%X=%X\n", num, i, num*i);
	}
	return 0; 
}
