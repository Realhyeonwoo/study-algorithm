#include <stdio.h>

int main()
{
  // ���ڿ� �Է� 
  char word[100];
  scanf("%s", word); 
  
  int len = 0; 
  while(word[len] != '\0') {
  	len++; 
  }
  
  //�Է� ���ڿ� ���ؼ� 
  int i = 0; 
  int count = 0; 
  while(word[i] != '\0') {
  	switch(word[i]){
  		case 'c':
  			word[i+1] == '=' || word[i+1] == '-' ? i += 2 : i += 1;
  			count++; 
  			break;
  		case 'l':
  		case 'n':  						
  			word[i+1] == 'j' ? i += 2 : i += 1;
  			count++;
  			break;
  		case 's':
  		case 'z':
  			word[i+1] == '=' ? i += 2 : i += 1;
  			count++;
  			break;
  		case 'd':
  			if(word[i+1] == '-') {
  				i+= 2; 
  				count++; 
			} else if(word[i+1] == 'z' && word[i+2] == '=') {
				i+= 3; 
  				count++; 
			} else {
				i++;
				count++; 
			}
			break;
		default:
			i++;
			count++; 
	}
	if(i > len ) break;
  }
  
  // ��� ��� 
  printf("%d", count); 
  return 0;
}
