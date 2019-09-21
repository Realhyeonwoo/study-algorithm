#include<stdio.h>

int main(void) {
	int num[3]; 
	int i = 0; 
	for(i=0 ;i<3; i++){
		scanf("%d", &num[i]);
	}
	
	for(i=0 ;i<3; i++){
		printf("%s\n", num[i]%2==0 ? "even" : "odd");
	}

	return 0; 
}
