#include<iostream>
using namespace std; 

int d[1000001]; 

int main(void) {
	int n; 
	cin >> n; 
	
	for(int i=2; i<=n; i++) {
		d[i] = d[i-1] + 1; 
		if(i%3 == 0) {
			if(d[i] > d[i/3] + 1) {
				d[i] = d[i/3] + 1;
			}
		}
		if(i%2 == 0) {
			if(d[i] > d[i/2] + 1) {
				d[i] = d[i/2] + 1; 
			}
		}
	}
	
	cout << d[n] << endl; 
	return 0; 
}

/*
	n =====> 1 
	d[n]: n을 1로 만드는 최소 횟수 
	d[1] = 0; 
	d[2] = 1; 
		
	/3 /2 -1 
	i - i/3 - 1
	i - i/2 - 1
	i - i-1 - 1
	d[n] = max(d[n/3], d[n/2], d[n-1]) + 1 
*/
