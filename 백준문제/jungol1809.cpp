#include<iostream>
using namespace std;

int N;
int arr[500001]; // 1 ~ 500000
int answer[500001]; // 1 ~ 500000
int main(void) {
	scanf("%d", &N); // ž�� ���� �Է� 
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=i-1; j>=1; j--) {
			if(arr[i] <= arr[j]) {
				answer[i] = j;
				break;
			}
		}
	}
	
	for(int i=1; i<=N; i++) {
		printf("%d ", answer[i]);
	}
	return 0;
}
