#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int N, M; // 행(세로): N, 열(가로): M 
int D; // 공격 거리 제한 
int map[16][16]; // 0 ~ 14 + 15(궁수)  
int copyMap[16][16]; // 0 ~ 14 + 15(궁수)  
bool v_archer[15]; // archer_dfs 방문 확인 
int answer = -9999;

int simulation(int archer_line) {
	int kill_count = 0;
	for(int archer=0; archer<M; archer++) {
		// 궁수 발견  
		if(copyMap[archer_line][archer]) {
			int archer_y = archer_line;
			int archer_x = archer;
			printf("====Archer[%d %d] ==> ", archer_y, archer_x);
			
			// 궁수가 죽일 수 있는 적이 있는지 확인 
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
			
			// 죽일 적이 있다면 실행  
			printf("====죽인 적 [%d %d]====\n", enemy_y, enemy_x);
			if(enemy_y != 9999 && enemy_x != 9999)  {
				copyMap[enemy_y][enemy_x] = 0;
				kill_count++;	
			}
		}
	}
	
	printf("죽인 적의 수: %d\n", kill_count);
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
			printf("\n=============(전)MAP=============\n");
			for(int y=0; y<=N; y++) {
				for(int x=0; x<M; x++) {
					printf("%d ", copyMap[y][x]);
				}
				printf("\n");
			}
			printf("=============MAP=============\n");
			
			enemy += simulation(y);
			printf("누적으로 적을 준인 수: %d\n", enemy);
			
			printf("=============(후)MAP=============\n");
			for(int y=0; y<=N; y++) {
				for(int x=0; x<M; x++) {
					printf("%d ", copyMap[y][x]);
				}
				printf("\n");
			}
			printf("=============MAP=============\n");
			
			
			// 한 줄 위로  
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
	} // 빈칸(0), 적(1) 
	
	
	// 궁수 배치 (M개 중 3개 뽑는 조합) 
	setArcher_dfs(0, 0);
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
