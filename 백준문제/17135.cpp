#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;

int N, M; // 행(세로): N, 열(가로): M 
int D; // 공격 거리 제한 
int map[16][16]; // 0 ~ (N-1) + N(궁수)  
int copyMap[16][16]; // 0 ~ (N-1) + N(궁수)  
bool v_archer[15]; // archer_dfs 방문 확인 
int answer = 0; // 정답 저장할 변수 
 
int simulation(int archer_line) {
	vector<pair<int, int> > enemy; 

	// 궁수 탐색 
	for(int archer=0; archer<M; archer++) {
		// 궁수 발견   
		if(copyMap[archer_line][archer]) {
			int archer_y = archer_line;
			int archer_x = archer;
			
			// 궁수가 죽일 수 있는 적이 있는지 확인 
			int min_d = 9999; 
			int ey = -1, ex = -1; 
			for(int x=0; x<M; x++) {
			for(int y=archer_line-1; y>=archer_line-D; y--) {
				if(y < 0) break;
				
					if(copyMap[y][x] == 0) continue;
					int d = abs(archer_y - y) + abs(archer_x - x);
					if(d <= D && d < min_d) {
						min_d = d;
						ey = y;
						ex = x;
					}
				}
			}
			// 처리 할 적이 있으면 해당 적의 좌표를 저장 
			if(ey != -1 && ex != -1) {
				enemy.push_back(make_pair(ey, ex));	
			}
		}
	}
	
	// vector에 저장된 죽일 적의 좌표로 해당 칸 0 && 죽인 수 카운트
	int kill_count = 0;
	for(int i=0; i<enemy.size(); i++) {
		pair<int, int> pos = enemy[i];
		int enemy_y = pos.first;
		int enemy_x = pos.second;
		if(copyMap[enemy_y][enemy_x] != 0) {
			copyMap[enemy_y][enemy_x] = 0;	
			kill_count++;
		}
	}
			
//	printf("죽인 적의 수: %d\n", kill_count);
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
			enemy += simulation(y);
			
			// 한 줄 위로  
			for(int x=0; x<M; x++) {
				copyMap[y-1][x] = copyMap[y][x];
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
