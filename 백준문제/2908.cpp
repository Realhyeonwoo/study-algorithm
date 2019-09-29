#include <stdio.h>

int main()
{
  // 문자열 입력 
  char num1[3], num2[3]; 
  scanf("%s %s", num1, num2); 
  
  //뒤집은 문자열의 int형으로 변환 
  int n1 = (num1[2]-'0')*100 + (num1[1]-'0')*10 + (num1[0]-'0')*1;
  int n2 = (num2[2]-'0')*100 + (num2[1]-'0')*10 + (num2[0]-'0')*1;
  
  printf("%d", n1>n2 ? n1 : n2);
  
  return 0;
}
