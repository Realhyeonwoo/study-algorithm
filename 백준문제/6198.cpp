#include<iostream>
#include<stack>
using namespace std;

int N;
long long arr[80001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> N;
	long long h;
	for(int i=1; i<=N; i++) {
		cin >> h;
		arr[i] = h;
	}
	
	// SIMULATION
	stack<int> S;
	long long sum = 0;
	for(int i=1; i<=N; i++){
		while(!S.empty() && S.top() <= arr[i]) {
			S.pop();
		}
		
		S.push(arr[i]);
		
		sum += S.size() - 1;
	}
	
	
	// OUTPUT
	cout << sum << "\n";
	
	return 0;
}
