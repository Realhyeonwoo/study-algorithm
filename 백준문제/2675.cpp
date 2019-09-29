#include <stdio.h>

int count[200]; // 알파벳 카운트 갯수 저장 
int index; // 최대 갯수인 알파벳 인덱스 저장 

int main()
{
  // 문자열 입력 
  char word[1000001]; 
  scanf("%s", word); 
  
  // 입력 문자열을 모두 대문자로 전환  
  int len = 0; 
  while(word[len] != '\0') {
  	if('a' <= word[len] && word[len] <= 'z'){
  		word[len] -= 32; 
	}
  	len++;
  }
  
  // 입력 문자열 카운트 
  len = 0; 
  while(word[len] != '\0') {
  	count[word[len]]++; 
  	len++;
  }
  
  // 많이 입력된 알파벳 갯수 찾기 
  int max = count[0];
  for(int i=0; i<200; i++) {
  	if(max < count[i]) {
  		index = i; 
  		max = count[i];
	}
  }

  // 최대갯수가 같은 문자가 있는지 검사 
  int temp = 0; 
  for(int i=0; i<200; i++) {
  	if(count[i] == max) {
  		temp++; 
	}
  }
  
  // 검사 결과에 따라 출력 
  if(temp > 1) {
  	printf("?"); 
  } else {
  	printf("%c", index); 	
  }
  
  return 0;
}
