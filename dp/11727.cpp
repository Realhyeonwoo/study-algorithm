#include<iostream>
#define MAX 1001
using namespace std;

int dp[1001];
int n;

int main(void) {
	scanf("%d", &n);
	dp[1] = 1, dp[2] = 3;
	for(int i=3; i<=n; i++) {
		dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
	}
	
	printf("%d\n", dp[n]);
	return 0;
}
