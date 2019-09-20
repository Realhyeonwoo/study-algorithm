#include <stdio.h>

int main()
{
	int y, m; 
	scanf("%d-%d", &y, &m); 
	
	printf("%06d%07d \n", y, m);

    return 0;
}
