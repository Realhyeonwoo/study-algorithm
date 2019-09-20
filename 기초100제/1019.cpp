#include <stdio.h>

int main()
{
	int y, m, d; 
	scanf("%d.%d.%d", &y, &m, &d); 
	
	printf("%0004d.%02d.%02d \n", y, m, d);

    return 0;
}
