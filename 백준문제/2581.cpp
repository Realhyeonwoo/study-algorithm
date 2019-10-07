#include<cstdio>

int main(void) {
	int m, n; 
	scanf("%d %d", &m, &n); 
	
	int min = -1; 
	int sum = 0; 
	
	for(int i=m; i<=n; i++) {
		int check = 0; 
		for(int j=2; j<i; j++) {
			if(i % j == 0) {
				check++; 	
				break; 
			}
		}
	
		if(i != 1 && check == 0) {
				if(min == -1) min = i; 
				sum += i; 
		}
	}
	
	if(min == -1) {
		printf("%d\n", min); 
	} else {
		printf("%d\n%d\n", sum, min); 
	}
	return 0; 
}
