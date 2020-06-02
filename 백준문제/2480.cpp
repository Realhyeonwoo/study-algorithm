#include<iostream>
#include<algorithm>
using namespace std;

int arr[7];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int num;
	for(int i=0; i<3; i++) {
		cin >> num;
		arr[num]++;
	}
	int Max = *max_element(arr, arr+7);
	int idx = 6;
	for(int i=6; i>=1 ; i--) {
		if(Max == arr[i]) {
			idx = i;
			break;
		}
	}
	
	int answer = 0;
	if(Max == 3) {
		answer = 10000 + 1000 * idx;		
	} else if(Max == 2) {
		answer = 1000 + 100 * idx;
	} else if(Max == 1) {
		answer = 100 * idx;
	}
	
	cout << answer << "\n";
	
	return 0; 
}

