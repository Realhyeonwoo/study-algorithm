#include<cstdio>
#include<algorithm>
int d[2][100001];
int a[2][100001];

int main(void) {
	int T;
	scanf("%d", &T);
	
	while(T--) {
		// ют╥б 
		int N;
		scanf("%d", &N);	
		for(int i=0; i<2; i++) {
			for(int j=1; j<=N; j++) {
				scanf("%d", &a[i][j]); 
			}
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=0; j<3; j++) {
				switch(j){
					case 0:
						int temp = max(a[i-1][1], a[i-1][2]);
						a[i][0] = max(temp, a[i-1][0]);
						break;
					case 1:
						a[i][1] = max(a[i-1][0], a[i-1][2]);
						break;
					case 2:
						a[i][2] = max(a[i-1][0], a[i-1][1]);
						break;
				}
			}
		}
	}
	
	int temp = max(a[i][1], a[i][2]);
 	long long int answer = max(temp, a[i][0]);
 	
 	printf("%d\n", answer);
	
	return 0; 	
}
