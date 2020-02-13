#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	
	for(int i=N; i>=4; i--) {
		bool flag = true;
		int num = i;
		while(num != 0) {
			int check = num % 10;
			if(check != 4 && check != 7) {
				flag = false;
				break;
			}
			num /= 10;
		}
		if(flag) {
			printf("%d\n", i);
			break;
		}
	}
	return 0; 
}
