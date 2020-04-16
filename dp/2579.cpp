#include<iostream>
#include<algorithm>

#define MAX 301
using namespace std;

int dp[MAX][3], N;
int score[MAX];

int main(void) {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &score[i]);
	}
	dp[1][1] = score[1];
	dp[2][1] = score[1] + score[2];
	dp[2][2] = score[2];
	
	for(int i=3; i<=N; i++) {
		dp[i][1] = dp[i-1][2] + score[i];
		dp[i][2] = max(dp[i-2][1], dp[i-2][2]) + score[i];
	}

	printf("%d\n", max(dp[N][1], dp[N][2]));	

	return 0;
}	

