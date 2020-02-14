#include<iostream>
using namespace std;

int findSet(int num, int* arr) {
	if(num == arr[num]) return num;
	return arr[num] = findSet(arr[num], arr);

}

void unionSet(int num1, int num2, int* arr) {
	num1 = findSet(num1, arr);
	num2 = findSet(num2, arr);
	if(num1 == num2) return;
	arr[num2] = num1;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		int N, M;
		scanf("%d %d", &N, &M);
		int arr[101]; // 1 ~ 100 
		
		// makeSet
		for(int i=1; i<=N; i++) {
			arr[i] = i;
		}
		
		for(int i=0; i<M; i++) {
			int num1, num2;
			scanf("%d %d", &num1, &num2);
			unionSet(num1, num2, arr);
		}
		
		int count = 0;
		for(int i=1; i<=N; i++) {
			if(arr[i] == i) count++;
		}
		printf("#%d %d\n", test_case, count);
	}
	return 0;
}
