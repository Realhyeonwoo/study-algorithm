#include <stdio.h>

int count[200]; // ���ĺ� ī��Ʈ ���� ���� 
int index; // �ִ� ������ ���ĺ� �ε��� ���� 

int main()
{
  // ���ڿ� �Է� 
  char word[1000001]; 
  scanf("%s", word); 
  
  // �Է� ���ڿ��� ��� �빮�ڷ� ��ȯ  
  int len = 0; 
  while(word[len] != '\0') {
  	if('a' <= word[len] && word[len] <= 'z'){
  		word[len] -= 32; 
	}
  	len++;
  }
  
  // �Է� ���ڿ� ī��Ʈ 
  len = 0; 
  while(word[len] != '\0') {
  	count[word[len]]++; 
  	len++;
  }
  
  // ���� �Էµ� ���ĺ� ���� ã�� 
  int max = count[0];
  for(int i=0; i<200; i++) {
  	if(max < count[i]) {
  		index = i; 
  		max = count[i];
	}
  }

  // �ִ밹���� ���� ���ڰ� �ִ��� �˻� 
  int temp = 0; 
  for(int i=0; i<200; i++) {
  	if(count[i] == max) {
  		temp++; 
	}
  }
  
  // �˻� ����� ���� ��� 
  if(temp > 1) {
  	printf("?"); 
  } else {
  	printf("%c", index); 	
  }
  
  return 0;
}
