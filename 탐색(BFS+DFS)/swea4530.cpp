#include<iostream>
#include<algorithm>
using namespace std;

int T;
long long int A, B;

int main(void) {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		long long int answer = 0;
		
		scanf("%lld %lld", &A, &B);
		
		answer = B - A - 1;
		
		printf("%d\n", answer);
		
	}
	return 0;
}
