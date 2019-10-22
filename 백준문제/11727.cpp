#include<iostream>
#include<vector>
using namespace std; 

int main(void) {
	int n;
	cin >> n; 
	
	vector<int> d(n+1);
	
	d[0] = 1; d[1] = 1;
	for(int i=2; i<=n; i++) {
		d[i] = (d[i-1] + 2*d[i-2]) % 10007; 
	}
	
	cout << d[n] << endl;
	return 0; 
}
