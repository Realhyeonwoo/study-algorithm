#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void) {
	int n; 
	scanf("%d", &n);
	
	vector<int> d(n+1); 
	
	d[1] = 0;
	
	for(int i=2; i<=n; i++) {
		d[i] = d[i-1] + 1; 
		if(i%3 == 0 && d[i] > d[i/3]) {
			d[i] = d[i/3] + 1; 
		}
		if(i%2 == 0 && d[i] > d[i/2]) {
			d[i] = d[i/2] + 1; 
		}
	}
	
	cout << d[n] << endl; 
	return 0; 
}
