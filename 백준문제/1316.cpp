#include <stdio.h>

int check[26];

int main()
{
	// ���� �Է� 
	int N;
	scanf("%d", &N); 
	
	int count = 0; 
	for(int i=0; i<N; i++) {
		// ���ڿ� �Է� 
  		char word[100];
  		scanf("%s", word); 		
  		
  		// �Է� ���ڿ� ����  
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
