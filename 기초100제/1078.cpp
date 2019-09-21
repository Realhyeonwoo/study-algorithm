#include<stdio.h>

int main(void) {
	int c; 
	scanf("%d", &c);
	
	int sum = 0; 
	
	for(int a = 0; a <= c; a++) {
		if(a%2 == 0) sum += a; 
	}
	
	printf("%d", sum);
	return 0; 
}
