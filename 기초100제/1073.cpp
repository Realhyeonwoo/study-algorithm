#include<stdio.h>

int main(void) {
	int count, num;
	scanf("%d", &count);
	
	for(int i=0; i<count; i++) {
		scanf("%d", &num);
	}
	do {
		scanf("%d", &num); 	
		if(num != 0) {
			printf("%d\n", num);	
		}
	} while(num != 0); 
	
	return 0; 
}
