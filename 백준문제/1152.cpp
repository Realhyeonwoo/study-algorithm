#include <string>
#include <stdio.h>
#include<iostream>
using namespace std; 

int main()
{
  // ���ڿ� �Է� 
  char word[1000001]; 
  cin.getline(word, 1000001); 
	
  // ���� Ƚ�� �˻� 
  int count = 1; 
  int i=0; 
  while(word[i] != '\0' ) {
  	if(i==0 && word[i] == ' ') count--; 
	if(word[i] == ' ') count++; 
	if(word[i+1] == '\0' && word[i] == ' ') count--; 
  	i++;
  }
  
  // �ܾ��� ��
  printf("%d", count); 
  
  return 0;
}
