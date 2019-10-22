#include<cstdio>
#define mod 1000000000
int d[101][10]; 

int main(void) {
	int N;
	scanf("%d", &N);
	
	for(int i=0; i<10; i++) d[1][i] = 1; 
	
	for(int i=2; i<=N; i++) {
		for(int j=0; j<10; j++) {
			if(j == 0) {
				d[i][0] = d[i-1][1] % mod;
			} else if(j == 9) {
				d[i][9] = d[i-1][8] % mod;
			} else {
				d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % mod; 
			}
		}
	}
	int sum = 0; 
	for(int i=1; i<10; i++) {
		sum = (sum + d[N][i]) % mod; 
	}
	printf("%d\n", sum); 
	return 0; 
}
