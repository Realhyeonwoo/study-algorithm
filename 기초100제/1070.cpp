#include<stdio.h>

int main(void) {
	int num;
	do {
		scanf("%d", &num); 	
		if(num != 0) {
			printf("%d\n", num);	
		}
	} while(num != 0); 
	
	return 0; 
}
