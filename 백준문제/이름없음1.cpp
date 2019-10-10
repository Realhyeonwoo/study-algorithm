#include<cstdio>

int main(void) {
	int num;
	int sum = 5000;  
	while(scanf("%d", &num) != EOF) {
	 	
		
		switch(num) {
			case 1:
				sum -= 500;
				break;
			case 2:
				sum -= 800;
				break;
			case 3:
				sum -= 1000;
				break;
		}
	}
	printf("%d\n", sum); 
	
	return 0; 
} 	
