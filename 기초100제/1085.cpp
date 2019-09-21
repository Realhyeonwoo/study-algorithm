#include<stdio.h>

int main(void) {
	int num;
	scanf("%d", &num); 
	
	for(int i=1; i<=num; i++) {
		if(i % 3 != 0){
			printf("%d ", i);	
		}
	}
	return 0; 
}
