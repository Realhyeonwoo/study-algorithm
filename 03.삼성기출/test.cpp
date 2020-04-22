#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(void) {
//	vector<int> v;
//	
//	for(int i=0; i<10; i++) {
//		v.push_back(i);
//	}
//	for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
//	printf("\n\n");
//	v.erase(v.begin()+2, v.begin()+v.size());
//	
//	for(int i=0; i<v.size(); i++) printf("%d ", v[i]);

	deque<int> dq;
	deque<int> initDq(4);
	for(int i=0; i<initDq.size(); i++) {
		printf("%d ", initDq[i]);
	}
	printf("\n");
	
	for(int i=1; i<6; i++) {
		dq.push_back(i);
	}
	
	for(int i=0; i<dq.size(); i++) {
		printf("%d ", dq[i]);
	}
	printf("\n");
	
	dq.erase(dq.begin()+1, dq.begin()+dq.size());
	
	for(int i=0; i<dq.size(); i++) {
		printf("%d ", dq[i]);
	}
	printf("\n");
	
	for(int i=0; i<dq.size(); i++) {
		printf("%d ", dq[i]);
	}
	printf("\n");
	return 0;
}
