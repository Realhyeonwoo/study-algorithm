#include<iostream>
using namespace std;

int N, K, boy[7], girl[7];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N >> K;
	
	int sex, grade;
	for(int i=0; i<N; i++) {
		cin >> sex >> grade;
		if(sex == 0) { // girl
			girl[grade]++;
		} else if(sex == 1) { // boy
			boy[grade]++;
		}
	}
	
	int ans = 0;
	for(int i=1; i<7; i++) {
		while(girl[i] > 0) {
			girl[i] -= K;
			ans++;
		}
	}
	for(int i=1; i<7; i++) {
		while(boy[i] > 0) {
			boy[i] -= K;
			ans++;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
