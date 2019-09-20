#include <stdio.h>

int main()
{
	char word[2001]; 
	
	fgets(word, 2000, stdin); 
	
	printf("%s \n", word); 

    return 0;
}
