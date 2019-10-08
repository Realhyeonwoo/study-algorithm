#include<cstdio>

int main(void) {
	int number[10000] = {0, }; 
		
		for(int i=2; i<10000; i++) {
			if(!number[i]) {
				for(int j=2; i*j<10000; j++){
					number[i*j] = 1; 
				}
			}
		}
		
	int T; 
	scanf("%d", &T); 
	
	while(T--) {
		int num;
		scanf("%d", &num); 
		
		int max = -1; 
		
		for(int i=2; i<=num/2; i++) {
			if(!number[i] && !number[num-i]) {
				if(max < i) max = i;
			}
		}
		
		printf("%d %d\n", max, num-max); 
	}
	return 0; 
}
