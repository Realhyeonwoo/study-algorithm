#include<iostream>
using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// INPUT
	// SIMULATION
	int n, sum = 0, min = 987654321;
	for(int i=0; i<7; i++) {
		cin >> n;
		if(n%2 != 0) {
			sum += n;
			if(n < min) min = n;
		}
	}
	
	// OUTPUT
	if(sum == 0) cout << -1 << "\n";
	else cout << sum << "\n" << min << "\n";
	
	return 0;
}
