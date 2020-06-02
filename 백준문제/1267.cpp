#include<iostream>
using namespace std;

int N, ySum, mSum;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// INPUT
	// SIMULATION
	cin >> N;
	int time;
	for(int i=0; i<N; i++) {
		cin >> time;
		ySum += (time/30 + 1) * 10;
		mSum += (time/60 + 1) * 15;
	}
	
	// OUTPUT
	if(ySum < mSum) cout << 'Y' << " " << ySum << "\n";
	else if(ySum > mSum) cout << 'M' << " " << mSum << "\n";
	else cout << 'Y' << " " << 'M' << " " << mSum << "\n";
	
	return 0;
}
