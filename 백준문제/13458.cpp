#include<iostream>
using namespace std;

int N; // 시험장 수
int room[1000001]; // 시험장: 1 ~ 1000000
int B; // 총감독관 능력 
int C; // 부감독관 능력 


int main(void) {
	// 입력 
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		int num;
		scanf("%d", &num);
		room[i] = num;
	}
	scanf("%d %d", &B, &C);
	
	 
 	long long sum = N; 
 	
 	for(int i=1; i<=N; i++) {
 		int namuji = 0; 
 		room[i] -= B;

 		if(room[i] <= 0) continue;
 		
 		namuji = room[i] / C;
 		if(room[i] % C != 0) namuji += 1;
		sum += namuji;
	}
	
	printf("%ld\n", sum);
	return 0;
}
