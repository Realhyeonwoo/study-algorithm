#include<stdio.h>

int main(void) {
	char c;
	scanf("%c", &c);
	
	for(char a = 'a'; a <= c; a++) {
			printf("%c ", a);	
	}
	return 0; 
}
