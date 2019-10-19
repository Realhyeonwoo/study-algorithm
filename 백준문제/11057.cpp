#include<cstdio>
#define mod 10007
int d[100001][3]; 

int main(void) {
	int N;
	scanf("%d", &N);
	
	for(int i=0; i<10; i++) d[1][i] = 1; 
	
	for(int i=2; i<=N; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<=j; k++) {
				d[i][j] += d[i-1][k]; 
				d[i][j] %= mod; 
			}
		}
	}
	long long sum = 0; 
	for(int i=0; i<10; i++) {
		sum += d[N][i]; 
	}
	sum %= mod; 
	printf("%d\n", sum); 
	return 0; 
}
