#include<iostream>
#include<cstring>
using namespace std;

int N, M, L; // N: �ڸ���(1����), M: �ִ� ���� �� �ִ� Ƚ��, L: ��° 
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
		if(getBall[throwIndex]%2 != 0) { // Ȧ�� => �ð���� L��ŭ 
			getIndex = throwIndex + L;
			if(getIndex > N) {
				getIndex -= N;
			}
		} else { // ¦�� => �ݽð���� L��ŭ 
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
