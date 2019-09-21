#include<stdio.h>

int count[24]; 

int main(void) {
	
	int num;
	scanf("%d", &num); 
	
	for(int i=0 ; i<num ; i++) {
		int n; 
		scanf("%d", &n); 	
		count[n]++; 
	}
	
	for(int i=1; i<24; i++) {
		printf("%d ", count[i]); 
	}
	return 0; 
}
