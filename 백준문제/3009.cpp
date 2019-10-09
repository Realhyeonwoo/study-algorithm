#include<cstdio>
#include<cmath>

int main(void) {
	while(1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c); 
		if(a==0 && b==0 && c==0) break;
		
		int res; 
		
		if(a < b){
			if(b < c) {
				res = pow(c, 2) - pow(a, 2) - pow(b, 2);
			} else {
				res = pow(b, 2) - pow(a, 2) - pow(c, 2);
			}
		} else {
			if(a < c) {
				res = pow(c, 2) - pow(a, 2) - pow(b, 2);	
			} else {
				res = pow(a, 2) - pow(c, 2) - pow(b, 2);
			}
		}
		res == 0 ? printf("right\n") : printf("wrong\n"); 
	}
	
	
	return 0; 
}
