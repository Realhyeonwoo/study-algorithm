#include<iostream>
#include<algorithm>
using namespace std;

int num[21];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	// INPUT
	for(int i=1; i<=20; i++) num[i] = i;
	
	// SIMULATION
	int a, b;
	for(int i=1; i<=10; i++) {
		cin >> a >> b;
		reverse(num+a, num+b+1);
	}
	
	// OUTPUT
	for(int i=1; i<=20; i++) {
		cout << num[i] << " ";
	}
	
	return 0;
}
