#include<cstdio>

int main(void) {
	int N;
	scanf("%d", &N);
	
	int count = 0; 
	
	while(N--) {
		int check = 0; 
		
		int num;
		scanf("%d", &num);
		
		
		// num 이 소수인지 판별 
		for(int i=2; i<num; i++) {
			if(num % i == 0) {
				check++; 
				break;
			}
		}
		
		if(num != 1 && check == 0 || num == 2) count++; 
		
	}
	
	printf("%d\n", count);
	return 0; 
}
