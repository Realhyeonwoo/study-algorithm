#include<iostream>
using namespace std;

int main(void) {
	int maxV = -1;
	int sum = 0;
	for(int sub=1; sub<=4; sub++) {
		int minus, plus;
		scanf("%d %d", &minus, &plus);
		sum = sum - minus + plus;
		if(sum > maxV) maxV = sum;
	}
	printf("%d\n", maxV);
	return 0;
}
