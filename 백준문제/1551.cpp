#include<iostream>
using namespace std;

int num[20];
int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) {
		char ch;
		scanf("%d",&num[i]);
		if(i != N-1) {
			scanf("%c",&ch);	
		}
	}
	
	int k = 1;	
	for( ; k<=K; k++) {
		for(int i=1; i<N+1-k; i++) {
			int temp = num[i] - num[i-1];
			num[i-1] = temp;
		}
	}
	
	for(int i=0; i<N+1-k; i++) {
		printf("%d", num[i]);
		if(i != N-k) {
			printf(",");	
		}
	}
		
	return 0;
}
