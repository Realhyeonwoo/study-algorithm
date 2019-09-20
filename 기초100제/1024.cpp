#include <stdio.h>

int main()
{
	char word[21]; 
	scanf("%s", &word); 
	
	int i = 0; 
	
	do{
		printf("\'%c\'\n", word[i++]);
	}while(word[i] != '\0') ;

    return 0;
}
