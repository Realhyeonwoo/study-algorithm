#include<stdio.h>

int main(void) {
	int num; 
	scanf("%d", &num); 
	
	int sum = 0, i = 1; 
	
	while(1) {
		sum += i;
		
		if(sum >= num){
			printf("%d", i); 
			break;		
		}
		
		i++; 
	}
	return 0; 
}
