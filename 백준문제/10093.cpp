#include<iostream>
#include<algorithm>
using namespace std;

long long A, B;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// INPUT
	cin >> A >> B;
	
	// SIMULATION
	// OUTPUT
	if(A > B) swap(A, B);
	
	if(A == B) {
		cout << 0 << "\n";
	} else {
		cout << B - A - 1 << "\n";
		A += 1;
		while(A != B) {
			cout << A << " ";
			A++;
		}	
	}
	
	return 0;
}
