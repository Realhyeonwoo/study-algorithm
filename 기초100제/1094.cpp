#include<stdio.h>

int count[10000]; 

int main(void) {
	
	int num;
	scanf("%d", &num); 
	
	for(int i=1 ; i<=num ; i++) {
		scanf("%d", &count[i]); 	
	}
	
	for(int i=num; i>=1; i--) {
		printf("%d ", count[i]); 
	}

	return 0; 
}
