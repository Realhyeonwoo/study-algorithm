#include<iostream>
using namespace std;

int func(int arr[], int len) {
	int check[101] = {0, };
	for(int i=0; i<len; i++) {
		if(check[100 - arr[i]]) return 1;
		check[arr[i]] = 1;
	}
	
	return 0;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int arr1[3] = {1, 52, 48};
	cout << func(arr1, 3) << "\n"; // 1
	int arr2[2] = {50, 42};
	cout << func(arr2, 2) << "\n"; // 0
	int arr3[4] = {4, 13, 63, 87};
	cout << func(arr3, 4) << "\n"; // 1
	
	return 0;
}
