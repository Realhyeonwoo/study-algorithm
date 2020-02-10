#include<iostream>
using namespace std;

int N; // ������ ��
int room[1000001]; // ������: 1 ~ 1000000
int B; // �Ѱ����� �ɷ� 
int C; // �ΰ����� �ɷ� 


int main(void) {
	// �Է� 
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
