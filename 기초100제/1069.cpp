#include<stdio.h>

int main(void) {
	char num;
	scanf("%c", &num); 
	
	switch(num) {
		case 'A':
			printf("best!!!"); break;
		case 'B':
				printf("good!!"); break;
		case 'C':
			printf("run!"); break;
		case 'D':
			printf("slowly~"); break;	
			default:	
				printf("what?");
	}

	return 0; 
}
