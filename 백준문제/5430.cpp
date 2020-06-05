#include<iostream>
#include<deque>
#include<string>
using namespace std;


deque<char> DQ;

void doR(void) {
	int dqSize = DQ.size();
	for(int i=0; i<dqSize; i++) {
		DQ.push_back(DQ.front());
		DQ.pop_front();
	}
}

bool doD(void) {
	if(DQ.size()) return true;
	DQ.pop_front();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	string op, arr;
	int n, num[100005];
	for(int tc=1; tc<=T; tc++) {
		// INIT
		DQ.clear();
		
		// INPUT
		cin >> op >> n >> arr;
		cin >> arr;
		for(int i=0; i<n; i++) {
			if(i%2 != 0) DQ.push_back(arr[i]);
		}
		cin >> arr;
		// SIMULATION
		for(int i=0; i<op.length(); i++) {
			bool isError = false;
			if((i<op.length()-1) && op[i] == 'R' && op[i+1] == 'R') {
				i+=2;
				continue;
			} else if(op[i] == 'R') {
				doR();
			} else if(op[i] == 'D') {
				if(doD()) isError = true;
			}
			
			if(isError) cout << "error" << "\n";
		}
		
		// OUTPUT
		for(int i=0; i<DQ.size(); i++) cout << DQ[i] << " ";
		cout << '\n';
	}
	
	return 0;
}
