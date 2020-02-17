#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int N, M; // ��(����): N, ��(����): M 
int D; // ���� �Ÿ� ���� 
int map[16][16]; // 0 ~ 14 + 15(�ü�)  
int copyMap[16][16]; // 0 ~ 14 + 15(�ü�)  
bool v_archer[15]; // archer_dfs �湮 Ȯ�� 
int answer = -9999;

int simulation(int archer_line) {
	int kill_count = 0;
	for(int archer=0; archer<M; archer++) {
		// �ü� �߰�  
		if(copyMap[archer_line][archer]) {
			int archer_y = archer_line;
			int archer_x = archer;
			printf("====Archer[%d %d] ==> ", archer_y, archer_x);
			
			// �ü��� ���� �� �ִ� ���� �ִ��� Ȯ�� 
			int min_d = 9999; 
			int enemy_y = 9999, enemy_x=9999;
			for(int y=0; y<archer_line; y++) {
				for(int x=0; x<M; x++) {
					int d = abs(archer_y - y) + abs(archer_x - x);
					if(d <= D && copyMap[y][x] != 0 ) {
						if(d < min_d) {
							enemy_y = y;
							enemy_x = x;	
						}
					}
				}
			}
			
			// ���� ���� �ִٸ� ����  
			printf("====���� �� [%d %d]====\n", enemy_y, enemy_x);
			if(enemy_y != 9999 && enemy_x != 9999)  {
				copyMap[enemy_y][enemy_x] = 0;
				kill_count++;	
			}
		}
	}
	
	printf("���� ���� ��: %d\n", kill_count);
	return kill_count; 
}

void setArcher_dfs(int start, int cnt) {
	if(cnt == 3) {
		// RESET && COPY map (map -> copyMap) 
		memset(copyMap, 0, sizeof(copyMap));
		for(int y=0; y<N; y++) {
			for(int x=0; x<M; x++) {
				copyMap[y][x] = map[y][x];
			}
		}
		// SET archer to copyMap
		for(int i=0; i<15; i++) {
			if(v_archer[i]) {
				copyMap[N][i] = 5;
			}
		}
		
		
		// SIMULATION
		int enemy = 0;
		for(int y=N; y>0; y--) {
			printf("===============Line: %d===============\n", y);
			printf("\n=============(��)MAP=============\n");
			for(int y=0; y<=N; y++) {
				for(int x=0; x<M; x++) {
					printf("%d ", copyMap[y][x]);
				}
				printf("\n");
			}
			printf("=============MAP=============\n");
			
			enemy += simulation(y);
			printf("�������� ���� ���� ��: %d\n", enemy);
			
			printf("=============(��)MAP=============\n");
			for(int y=0; y<=N; y++) {
				for(int x=0; x<M; x++) {
					printf("%d ", copyMap[y][x]);
				}
				printf("\n");
			}
			printf("=============MAP=============\n");
			
			
			// �� �� ����  
			for(int x=0; x<M; x++) {
				copyMap[N-1][x] = copyMap[N][x];
			}
		
		}
		

	
		if(answer < enemy) answer = enemy;
		
		return;
	}
	
	for(int i=start; i<M; i++) {
		if(v_archer[i]) continue;
		v_archer[i] = true;
		setArcher_dfs(i, cnt+1);
		v_archer[i] = false;
	}
}

int main(void) {
	//INPUT
	scanf("%d %d %d", &N, &M, &D); 
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
		}
	} // ��ĭ(0), ��(1) 
	
	
	// �ü� ��ġ (M�� �� 3�� �̴� ����) 
	setArcher_dfs(0, 0);
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
