#include<iostream>
using namespace std;

int K, N; // K: start num, N: number question
// 3 30 => 210s
int total = 210;

int main(void) {
	scanf("%d", &K);
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) {
		int time;
		char ans;
		scanf("%d %c", &time, &ans);
		total -= time;
		if(total <= 0) {
			printf("%d\n", K);
			break;
		}
		
		switch(ans) {
			case 'T':
				if(K == 8) {
					K = 1;
				} else {
					K += 1;	
				}
				break;
			case 'N':
			case 'P':
				break;
		}		
	}
	return 0;
}
