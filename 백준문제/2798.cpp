#include<cstdio>

int card[100]; 

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M); 
	for(int i=1; i<=N; i++){
		scanf("%d", &card[i]); 
	}
	
	int max = -1; 
	for(int i=1; i<=N; i++) {
		for(int j=i+1; j<=N; j++) {
			for(int k=i+2; k<=N; k++) {
				int sum = 0; 
				sum = card[i] + card[j] + card[k]; 
				if(sum <= M && max < sum) {
					max = sum; 
				}
			}
		}
	}
	
	printf("%d\n", max);
	return 0; 
}
