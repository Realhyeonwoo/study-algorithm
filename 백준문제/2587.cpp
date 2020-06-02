#include<iostream>
#include<algorithm>
using namespace std;

int arr[5];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// INPUT
	int n, sum = 0;
	for(int i=0; i<5; i++) {
		cin >> n;
		sum += n;
		arr[i] = n;
	}
	
	// SIMULATION
	sum /= 5;
	sort(arr, arr+5);
	
	// OUTPUT
	cout << sum << "\n" << arr[2] << "\n";
	
	return 0;
}
