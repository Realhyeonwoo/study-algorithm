#include <stdio.h>

int check[26];

int main()
{
	// 갯수 입력 
	int N;
	scanf("%d", &N); 
	
	int count = 0; 
	for(int i=0; i<N; i++) {
		// 문자열 입력 
  		char word[100];
  		scanf("%s", word); 		
  		
  		// 입력 문자열 길이  
  		int len = 0; 
  		while(word[len] != '\0') len++; 
  		
  		for(int j=0; j<len; j++) {
  			for(int k=0; k<j; k++) {
  				if(word[k] == word[j]) {
  					if(j-k != 1) {
  						break; 	
					}
				}

			}
		}
	}
	
	printf("%d", count); 
  
  
  return 0;
}
