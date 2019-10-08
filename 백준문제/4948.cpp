#include<cstdio>

int main(void) {
	while(1) {
		int number[250000] = {0, }; 
		number[0] = 1; 
		number[1] = 1;
		
		int num;
		scanf("%d", &num); 
		if(num == 0) break;
		
		for(int i=2; i<=num*2; i++) {
			if(!number[i]) {
				for(int j = 2; i*j <= num*2; j++) {
					number[i*j] = 1; 
				}
			}
		}
		
		int count = 0; 
		for(int k=num+1; k<=num*2; k++) {
			if(!number[k])count++;
		}
		
		printf("%d\n", count); 
		
	}
	return 0; 
}
