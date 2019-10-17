#include<iostream>
#include<algorithm>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	int N;
	cin >> N; 
	
	int firstNum = 666; 
	int count = 1;
	
	while(1) {
		if(N == count) break;
		
		firstNum++; 
		
		int temp = firstNum; 
		int flag = 0; 

		while(temp) {
			if(temp%10 == 6) {
				flag++;
			} else if(flag < 3){
				flag = 0; 
			}
			temp /= 10; 
		}
		
		if(flag >= 3)count++; 
	}
	
	cout << firstNum;
	
	return 0; 
}
