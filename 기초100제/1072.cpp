#include<stdio.h>

int main(void) {
	int count, num;
	scanf("%d", &count);
	
	for(int i=0; i<count; i++) {
		scanf("%d", &num);
		printf("%d\n", num);
	}
		
	return 0; 
}
