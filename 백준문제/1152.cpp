#include <string>
#include <stdio.h>
#include<iostream>
using namespace std; 

int main()
{
  // 문자열 입력 
  char word[1000001]; 
  cin.getline(word, 1000001); 
	
  // 띄어쓰기 횟수 검사 
  int count = 1; 
  int i=0; 
  while(word[i] != '\0' ) {
  	if(i==0 && word[i] == ' ') count--; 
	if(word[i] == ' ') count++; 
	if(word[i+1] == '\0' && word[i] == ' ') count--; 
  	i++;
  }
  
  // 단어의 수
  printf("%d", count); 
  
  return 0;
}
