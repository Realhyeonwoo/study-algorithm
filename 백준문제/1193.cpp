#include<cstdio>

int main(void) {
	int x; 
	scanf("%d", &x); 
	
	int n = 1;
	
	while((n*(n+1)/2) < x) {
		n++; 
	}
	
	n = n-1; 
	x = x - n*(n+1)/2 - 1; 
	
	int i, j; 
	
	if(n%2 == 0) {
		i = n - x; 
		j = x; 
	} else {
		i = x;
		j = n - x; 
	}
	
	printf("%d/%d\n", (i+1), (j+1)); 
	return 0; 
}
