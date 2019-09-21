#include<stdio.h>

int count[10000]; 

int main(void) {
	
	int num;
	scanf("%d", &num); 
	
	for(int i=1 ; i<=num ; i++) {
		scanf("%d", &count[i]); 	
	}
	
	int min = count[1];
	for(int i=2; i<=num; i++) {
		if(min > count[i]) min = count[i];
	}
	
	printf("%d", min); 
	return 0; 
}
