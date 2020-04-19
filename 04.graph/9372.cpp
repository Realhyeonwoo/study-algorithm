#include<iostream>
using namespace std;

int T, N, M;
int main(void) {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		scanf("%d %d", &N, &M);
		int a, b;
		for(int i=0; i<M; i++) {
			scanf("%d %d", &a, &b);
		}
		
		int answer = N - 1;
		printf("%d\n", answer);
	}
	return 0;
} 
