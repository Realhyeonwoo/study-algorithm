#include<iostream>
#include<deque>
using namespace std;

int N, M;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	deque<int> DQ(N);
	
	for(int i=0; i<N; i++) cout << DQ[i] << " ";
	
	0 0 0 0 0 0 0 0 0 9
	return 0;
}
