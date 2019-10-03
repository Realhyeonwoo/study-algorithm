#include<cstdio>
#include<cmath>

int main(void) {
	int num; 
	scanf("%d", &num); 
	
	while(num--) {
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);	
		
		int Y = int(ceil((double)N / H));
		int X = N % H == 0 ? H : N % H; 
		printf("%d%02d\n", X, Y); 
	}
	
	return 0; 
}

/*
  h  w  n
 30 50 72
 
 12
*/
