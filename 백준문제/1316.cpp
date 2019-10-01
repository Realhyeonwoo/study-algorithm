#include<iostream>
using namespace std; 

bool check[26] = {false, };

bool wordCheck(string word) {
	for(int i=0; i<word.length(); i++) {
		if(check[word[i] - 'a']) {
			return false; 
		} else {
			char temp = word[i]; 
			check[word[i] - 'a'] = true; 
			
			while(1) {
				if(temp != str[++i]) {
					i--;
					break; 
				}
			}
		}
	}
	return true; 
}

int main()
{
	// 갯수 입력 
	int N;
	scanf("%d", &N); 
	
	int count = 0; 
	for(int i=0; i<N; i++) {
		// 문자열 입력 
  		string word;
  		cin >> word; 
  		
  		if(wordCheck(word)) count++; 
  	}
	
	printf("%d", count); 

  return 0;
}
