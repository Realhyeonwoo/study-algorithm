/*
	특정한 값을 기준으로 큰 숫자와 작은 숫자를 나누면 어떨까? 
	O(n*logn)
	최악의 경우 => O(n^2) => 이미 정렬되 있는 경우(1, 2, 3, 4, ..... , 9, 10) 
*/

#include<stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int* data, int start, int end) {
	if(start >= end) {
		return;
	}
	int pivot = start;
	int left = start + 1;
	int right = end;
	int temp;
	
	while(left <= right) {
		while(left <= end && data[left] <= data[pivot]) {
			left++;
		}
		while(right > start && data[right] >= data[pivot]) {
			right--;
		}
		if(left > right) {
			temp = data[right];
			data[right] = data[pivot];
			data[pivot] = temp;
		} else {
			temp = data[left];
			data[left] = data[right];
			data[right] = temp;
		}
	}
	
	quickSort(data, start, right-1);
	quickSort(data, right+1, end);
}

int main(void) {
	quickSort(data, 0, number-1);
	
	for(int i=0; i<10; i++){
		printf("%d ", data[i]);
	}
	
	return 0; 
}
