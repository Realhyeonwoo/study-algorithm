#include<cstdio>

int main(void) {
	int num;
	while(1) {
		scanf("%d", &num);	
		if(num == 0) break; 
	
		int count = 0; 
		
		for(int i=num; i<=num*2; i++) {
			int check = 0; 
			for(int j=2; j<num*2; j++) {
				if(i%j == 0) {
					check++; 
					break;
				}
			}
			if(i != 1 && check == 0) {
				printf("%d ", i); 
				count++; 
			}
		}
		
		printf("%d\n", count); 
	}
	
	return 0; 
