#include<iostream>
using namespace std;

void fromNtoOne(int n) {
	if(n == 0) return;
	cout << n << ' ';
	fromNtoOne(n-1);
}

int sumOneToN(int n) {
	if(n == 0) return 0;
	return n + sumOneToN(n-1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	fromNtoOne(n);
	cout << '\n';
	cout << sumOneToN(n) << '\n';
	return 0;
}
