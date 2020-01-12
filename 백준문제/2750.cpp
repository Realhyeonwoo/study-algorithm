#include<stdio.h>

int main(void) {
	int array[1001];
	int n, i, j;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		scanf("%d", &array[i]);
	}
	
	for(i=1; i<=n; i++) {
		for(j=1; j<=n-i; j++) {
			if(array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	
	for(i=1; i<=n; i++) {
		printf("%d ", array[i]);
	}
	return 0; 
}
