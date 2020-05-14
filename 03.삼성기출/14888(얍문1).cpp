#include<iostream>
#include<cmath>

#define MAX 11
using namespace std;

int N, arr[MAX], Plus, Minus, Multiple, Divide;
int Max_Value = -1000000001, Min_Value = 1000000001;

void dfs(int pl, int mi, int mul, int div, int sum, int idx, int cnt) {
	if(cnt == N-1)	 {
		if(Max_Value < sum) Max_Value = sum;
		if(Min_Value > sum) Min_Value = sum;
		return;
	}
	
	if(pl < Plus) dfs(pl+1, mi, mul, div, sum + arr[idx], idx+1, cnt+1);
	if(mi < Minus) dfs(pl, mi+1, mul, div, sum - arr[idx], idx+1, cnt+1);
	if(mul < Multiple) dfs(pl, mi, mul+1, div, sum * arr[idx], idx+1, cnt+1);
	if(div < Divide) dfs(pl, mi, mul, div+1, sum / arr[idx], idx+1, cnt+1);
}

int main(void) {
	// INPUT
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);
	scanf("%d %d %d %d", &Plus, &Minus, &Multiple, &Divide);
	
	// SIMULATION
	dfs(0, 0, 0, 0, arr[0], 1, 0);
	
	// OUTPUT
	printf("%d\n%d\n", Max_Value, Min_Value);
	return 0;
}
