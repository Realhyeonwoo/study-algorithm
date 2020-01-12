//#include<stdio.h>
//
//int array[1000001];
//
//void quickSort(int* data, int start, int end) {
//	if(start >= end) {
//		return;
//	}
//	int pivot = start;
//	int left = start + 1;
//	int right = end;
//	int temp;
//	
//	while(left <= right) {
//		while(left <= end && data[left] <= data[pivot]) {
//			left++;
//		}
//		while(right > start && data[right] >= data[pivot]) {
//			right--;
//		}
//		if(left > right) {
//			temp = data[right];
//			data[right] = data[pivot];
//			data[pivot] = temp;
//		} else {
//			temp = data[right];
//			data[right] = data[left];
//			data[left] = temp;
//		}
//	}
//	
//	quickSort(data, start, right-1);
//	quickSort(data, right+1, end);
//}
//
//int main(void) {
//	int n;
//	
//	// 입력 
//	scanf("%d", &n);
//	for(int i=1; i<=n; i++) {
//		scanf("%d", &array[i]);
//	}
//	
//	quickSort(array, 1, n);
//	
//	// 출력 
//	for(int i=1; i<=n; i++){
//		printf("%d\n", array[i]);
//	}
//	return 0; 
//}

#include<stdio.h>
#include<algorithm>

int number, data[1000000];

int main(void) {
	scanf("%d", &number);
	for(int i=0; i<number; i++) {
		scanf("%d", &data[i]);
	}
	std::sort(data, data + number);
	for(int i=0; i<number; i++) {
		printf("%d\n", data[i]);
	}
	return 0; 
}
