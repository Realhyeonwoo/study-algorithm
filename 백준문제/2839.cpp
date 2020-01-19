#include<iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n); 
	
	int n3 = 0, n5 = 0;
	int min = 9999;
	bool check = false;
	for(int i=0; i*3<=n; i++) {
		for(int j=0; j*5<=n; j++) {
			if((3*i + 5*j) == n) {
				check = true;
				if(min > i+j) {
					min = i+j; 
				}
			}
		}
	}
	
	if(check) {
		printf("%d\n", min);
	} else {
		printf("%d\n", -1);
	}
	return 0; 
}
