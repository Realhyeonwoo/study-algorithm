#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector<int> v;
	
	for(int i=0; i<10; i++) {
		v.push_back(i);
	}
	for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
	printf("\n\n");
	v.erase(v.begin()+2, v.begin()+v.size());
	
	for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
	return 0;
}
