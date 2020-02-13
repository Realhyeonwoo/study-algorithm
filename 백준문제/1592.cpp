#include<iostream>
#include<cstring>
using namespace std;

int N, M, L; // N: 자리수(1부터), M: 최대 받을 수 있는 횟수, L: 번째 
int getBall[1001];
int main(void) {
	memset(getBall, 0, sizeof(getBall));
	
	scanf("%d %d %d", &N, &M, &L);
	
	getBall[1]++;
	int throwIndex = 1;
	int getIndex = 1;
	int count = 0;
	while(true) {
		if(getBall[throwIndex] == M) break;
		count++;
		if(getBall[throwIndex]%2 != 0) { // 홀수 => 시계방향 L만큼 
			getIndex = throwIndex + L;
			if(getIndex > N) {
				getIndex -= N;
			}
		} else { // 짝수 => 반시계방향 L만큼 
			getIndex = throwIndex - L;
			if(getIndex < 1) {
				getIndex += N;
			}
		}
		getBall[getIndex]++;
		throwIndex = getIndex; 
	}
	
	printf("%d\n", count);
	return 0;
}
