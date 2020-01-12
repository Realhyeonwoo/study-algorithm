/*
	각 숫자를 적절한 위치에 삽입하면 어떨까?  
	O(n^2)
*/

#include<stdio.h>

int main(void) {
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int i, j, temp;
	
	for(i=0; i<10; i++){
		j = i;
		while(array[j] > array[j+1]) {
			temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			j--;
		}
	}
	
	for(i=0; i<10; i++){
		printf("%d ", array[i]);
	}
	
	return 0;
}
