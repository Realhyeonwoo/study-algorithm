#include<cstdio>

int height[51];
int weight[51];
int rank[51];

int main(void) {
	int N;
	scanf("%d", &N); 
	for(int i=1; i<=N; i++) {
		scanf("%d %d", &height[i], &weight[i]); 
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(i==j) continue; 
			if(height[i] < height[j] && weight[i] < weight[j]) rank[i]++; 
		}
		rank[i]++;
	}
	
	for(int i=1; i<=N; i++) {
		printf("%d ", rank[i]); 
	}
	return 0; 	
}
