#include<cstdio>

int main(void) {
	int n;
	scanf("%d", &n); 
	
	int m = 0; 
	
	for(int i=1; i<1000000; i++) {
		int sum = i; 
		int num = i; 
		while(num != 0) {
			sum += num%10; 
			num = num/10; 
		}
		
		if(sum == n) {
			m = i; 
			break;
		}
	}
	
	printf("%d\n", m); 
	
	
	return 0; 
}
