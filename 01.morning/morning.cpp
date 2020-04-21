#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	
	a.erase(a.begin()+2, a.end());
	
	for(int i=0; i<a.size(); i++) printf("%d ", a[i]);
	return 0;
}
