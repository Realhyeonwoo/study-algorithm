#include<iostream>
#include<cstring>
using namespace std;

int A, B, C;
int time[101];

int main(void) {
	memset(time, 0, sizeof(time));
	scanf("%d %d %d", &A, &B, &C);
	int start=9999, end=-9999;
	for(int i=0; i<3; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		e = e - 1;
		for(int t=s; t<=e; t++) time[t]++;
		if(start > s) start = s;
		if(end < e) end = e;
	}
	
	int sum = 0;
	for(int i=start; i<=end; i++) {
		switch(time[i]) {
			case 1: sum += A*1; break;
			case 2: sum += B*2; break;
			case 3: sum += C*3; break;
		}
	}
	
	printf("%d\n", sum);
	return 0;
}
