#include<iostream>
#include<vector>
using namespace std;

int N;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N;
	vector<int> v;
	int num;
	for(int i=0; i<N; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	cin >> num;
	int ans = 0;
	for(int i=0; i<v.size(); i++) {
		if(num == v[i]) ans++;
	}
	
	cout << ans; 
	return 0;
}
