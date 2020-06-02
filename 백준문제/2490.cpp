#include<iostream>
using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// INPUT
	for(int tc=1; tc<=3; tc++) {
		int n, bae = 0;
		for(int i=0; i<4; i++) {
			cin >> n;
			if(n == 0) bae++;
		}
		
		// SIMULATION
		char ans;
		if(bae == 0) {
			ans = 'E';
		} else if(bae == 1) {
			ans = 'A';
		} else if(bae == 2) {
			ans = 'B';
		} else if(bae == 3) {
			ans = 'C';
		} else if(bae == 4) {
			ans = 'D';
		}
		
		// OUTPUT
		cout << ans << "\n";
	}
	return 0;
}
