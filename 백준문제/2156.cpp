#include<cstdio>

int d[10001];
int wine[10001];

int main(void) {
	int n;
	scanf("%d", &n); 
	for(int i=1; i<=n; i++){
		scanf("%d", &wine[i]);
	}
	
	d[1] = wine[1]; 
	d[2] = wine[1] + wine[2];
	for(int i=3; i<=n; i++) {
		d[i] = d[i-1]; 
		if(d[i] < d[i-2] + wine[i]){
			d[i] = d[i-2] + wine[i];
		}
		if(d[i] < d[i-3] + wine[i] + wine[i-1]) {
			d[i] = d[i-3] + wine[i] + wine[i-1];
		}
	}
	
	printf("%d\n", d[n]);
	return 0; 
}
