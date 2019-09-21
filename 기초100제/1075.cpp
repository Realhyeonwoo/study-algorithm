#include<stdio.h>

int main(void) {
	int count, num;
	scanf("%d", &count);
	
	for(int i=count-1; i>=0; i--) {
		printf("%d\n", i);
	}
		
	return 0; 
}
