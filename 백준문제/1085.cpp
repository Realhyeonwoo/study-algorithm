#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std; 

int main(void) {
	int x, y, w, h; 
	scanf("%d %d %d %d", &x, &y, &w, &h); 
	
	int res[4];
	res[0] = min(w-x, x);
	res[1] = min(h-y, y);
	res[2] = sqrt(pow(x, 2) + pow(y, 2));
	res[3] = sqrt(pow(w-x, 2) + pow(h-y, 2));
	
	int min = res[0]; 
	for(int i=1; i<4; i++) {
		if(min > res[i]) min = res[i];
	}
	
	printf("%d\n", min);
	
	return 0; 
}
