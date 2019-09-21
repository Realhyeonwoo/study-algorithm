#include<stdio.h>

int main(void) {
	char c = '1'; 
	
	while(1) {
		scanf("%c", &c); 
		if(c != 'q') {
			if(c != ' '){
				printf("%c\n", c); 	
			}
			
		} else {
			break;
		}
	}
	printf("q"); 	
	return 0; 
}
