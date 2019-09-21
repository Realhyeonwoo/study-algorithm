#include<stdio.h>

int main(void) {
	int num;
	scanf("%d", &num); 
	
	printf("%s\n", num < 0 ? "minus" : "plus");
	printf("%s\n", num % 2 == 0 ? "even" : "odd");

	return 0; 
}
