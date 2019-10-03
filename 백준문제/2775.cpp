#include<cstdio>
#include<cmath>


int home[15][15]; 

int check(int k, int i) {
	if(i == 1)	return 1;
	if(k == 0) return home[k][i];
	
	return check(k, i-1) + check(k-1, i); 
}

int main(void) {
	
	for(int i=1; i<15; i++) {
		home[0][i] = i;
	}
	
	int T; 
	scanf("%d", &T); 
	
	while(T--) {
		int k, i; 
		scanf("%d", &k);
		scanf("%d", &i);
		
		int result = check(k, i); 
		
		printf("%d\n", result); 
	}
	
	return 0; 
}

/*
  aÃþ bÈ£ => (a-1)Ãþ ÀÇ 1 ~ bÈ£ »ç¶÷µéÀÇ ¼ö  
  
  kÃþ¿¡ nÈ£¿¡´Â ¸î ¸íÀÌ »ì±î?  
  
  0Ãþ ºÎÅÍ / 1È£ ºÎÅÍ 
  0Ãþ iÈ£ ¿¡´Â i ¸í
  
  
     k 
    
  3Ãþ   1  5  15  35
  
  2Ãþ   1  4  10  20
  
  1Ãþ   1  3  6  10 
  
  0Ãþ   1  2  3  4  5  i 
  
  kÃþ iÈ£
  
  kÃþ (i-1)È£ + (k-1)Ãþ iÈ£ 
  1Ãþ 3È£
  1 + 2 + 3
  
  
  
  2Ãþ 3È£
  1 + 3 + 6
  
  1
  1 + 2
  1 + 2 + 3
  
  3Ãþ 4È£
  1 4 10 20
  
  1
  
  1 + 2
  
  1 + 2 + 3
  
  m = 0
  
  i-m * (i-m+1) / 2 
  
  m++ 
  
  
   
  1
  1 + 2
  3Ãþ 3È£ => k = 4, i = 3
   
  15 = 1 + 4 + 10 
       1 + (1+3) + (1+3+6) 
       
       1 + 
       
	   1 + 
	   1 + 2
	   
	   1 + 
	   1 + 2 + 
	   1 + 2 + 3
	   
	   int total = 0; 
	   
	   for(int i=1; i<k; i++) {
	   		
	   		for(int j=1; j<i+1; j++) { // 1, 2
	   			int sum = 0; 
	   			for(int m = 1; m<j+1; m++) { // 1
	   				sum += m; 
	   			}
	   		}
	   		total += sum; 
		}
  3Ãþ 2È£ 
  2Ãþ 3È£  
  
  1 
  1 + 3 
  1 + 3 + 4 
  
  
*/
