#include <stdio.h>

int main()
{
	int h, m, s; 
	scanf("%d.%d.%d", &h, &m, &s); 
	
	printf("%02d-%02d-%d", s, m, h);

    return 0;
}
