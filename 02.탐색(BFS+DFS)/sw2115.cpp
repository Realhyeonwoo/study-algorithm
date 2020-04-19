#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int N, M, C; // ������ũ��(N), �����ǰ���(M), ����ä���Ҽ��ִ��ִ��(C) 
int map[10][10];
int maxMap[10][10];
int result;

int getMaxBenefit() {
	int answer = 0, temp = 0;
	for(int y=0; y<N; y++) {
		for(int x=0; x<=N-M; x++) {
			for(int i=x+M; i<=N-M; i++) {
				temp = maxMap[y][x] + maxMap[y][i];
				answer = max(answer, temp);
			}
			for(int i=y+1; i<N; i++) {
				for(int j=0; j<=N-M; j++) {
					temp = maxMap[y][x] + maxMap[i][j];
					answer = max(answer, temp);
				}
			}
		}
	}
	
	return answer;
}

void calcMaxHoney(int y, int x, int cnt, int sum, int powSum) {
	if(sum > C) return; // �κ������� ���� ��ǥ�� C�� �ʰ��ϸ� ����
	if(cnt == M) {
		if(maxMap[y][x-M] <powSum) {
			maxMap[y][x-M] = powSum;
		}
		return;
	}
		
	// ����
	calcMaxHoney(y, x+1, cnt+1, sum+map[y][x], powSum+map[y][x] * map[y][x]);
		
	// ����
	calcMaxHoney(y, x+1, cnt+1, sum, powSum);
}


int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		memset(maxMap, 0, sizeof(maxMap));
		
		// INPUT
		scanf("%d %d %d", &N, &M, &C);
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				scanf("%d", &map[y][x]);
			}
		}
		
		// SIMULATION
		for (int y = 0; y < N; y++) {
			for (int x = 0; x <= N-M; x++) {
				calcMaxHoney(y, x, 0, 0, 0);
			}
		}

		result = getMaxBenefit();
		
		// OUTPUT
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}





