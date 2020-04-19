#include<iostream>
using namespace std;

int n, cnt;
int a[111], chk[111], ans[111];

int main(void) {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			chk[j] = ans[j];
		}
		dfs(a[i], i);
	}
	
	printf("%d\n", cnt);
	for(int i=1; i<=n; i++) {
		if(ans[i]) printf("%d\n", i);
	}
	return 0;
}
