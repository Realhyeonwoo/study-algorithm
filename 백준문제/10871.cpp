#include<iostream>
using namespace std;

int N, X, T;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N >> X;
	while(N--) {
		cin >> T;
		if(T < X) cout << T << ' ';
	}
	
	return 0;
}
