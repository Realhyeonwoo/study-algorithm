#include<iostream>
using namespace std;

int main(void) {
	int cup[4] = {0, 1, 2, 3};
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++) {
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		int index1, index2;
		for(int i=1; i<=3; i++) {
			if(cup[i] == c1) {
				index1 = i;
			}
		}
		for(int i=1; i<=3; i++) {
			if(cup[i] == c2) {
				index2 = i;
			}
		}
		
		int temp = cup[index1];
		cup[index1] = cup[index2];
		cup[index2] = temp;
		
	}
	
	printf("%d\n", cup[1]);
	
		
	
	
	return 0;
}
