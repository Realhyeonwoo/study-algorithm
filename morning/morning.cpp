#include<iostream>
#define MAX 7
using namespace std;

int num[MAX];

int getParent(int a) {
	if(a == num[a]) return a;
	return getParent(num[a]);
}
int main(void) {
	for(int i=1; i<MAX; i++) num[i] = i;
	return 0;
}
