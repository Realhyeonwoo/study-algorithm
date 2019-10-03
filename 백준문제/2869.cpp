#include<cstdio>
#include<cmath>
int main(void) {
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V); 
	
	double n = double(V - A) / (A - B) + 1; 
	
	n = ceil(n); 
	printf("%d\n", (int)n); 
	return 0; 
}
