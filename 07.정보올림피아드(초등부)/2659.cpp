#include<iostream>
#include<algorithm>
using namespace std;

int num[4];
int input = 987654321;

bool checkCorrect(int n, int a, int b, int c, int d) {
	if(a == 0 || b == 0 || c == 0 || d == 0) return false;
	
	int res = a * 1000 + b * 100 + c * 10 + d;
	res = min(res, b * 1000 + c * 100 + d * 10 + a);
	res = min(res, c * 1000 + d * 100 + a * 10 + b);
	res = min(res, d * 1000 + a * 100 + b * 10 + c);
	
	return res == n ? true : false;
}

int main(void) {
	for(int i=0; i<4; i++) {
		scanf("%d", &num[i]);
	}
	input = min(input, num[0]*1000 + num[1]*100 + num[2]*10 + num[3]);
	input = min(input, num[1]*1000 + num[2]*100 + num[3]*10 + num[0]);
	input = min(input, num[2]*1000 + num[3]*100 + num[0]*10 + num[1]);
	input = min(input, num[3]*1000 + num[0]*100 + num[1]*10 + num[2]);

	int answer = 1, number = 1111;
	while(1) {
		if(input == number) {
			
			break;	
		}
		if(!checkCorrect(number, number/1000, (number%1000)/100, ((number%1000)%100)/10, ((number%1000)%100)%10)) {
			number++;
			continue;
		}
		number++;
		answer++;
	}
	
	printf("%d\n", answer);
	return 0;
}


