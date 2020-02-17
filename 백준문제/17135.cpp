#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;

int N, M; // ��(����): N, ��(����): M 
int D; // ���� �Ÿ� ���� 
int map[16][16]; // 0 ~ (N-1) + N(�ü�)  
int copyMap[16][16]; // 0 ~ (N-1) + N(�ü�)  
bool v_archer[15]; // archer_dfs �湮 Ȯ�� 
int answer = 0; // ���� ������ ���� 
 
int simulation(int archer_line) {
	vector<pair<int, int> > enemy; 

	// �ü� Ž�� 
	for(int archer=0; archer<M; archer++) {
		// �ü� �߰�   
		if(copyMap[archer_line][archer]) {
			int archer_y = archer_line;
			int archer_x = archer;
			
			// �ü��� ���� �� �ִ� ���� �ִ��� Ȯ�� 
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
			// ó�� �� ���� ������ �ش� ���� ��ǥ�� ���� 
			if(ey != -1 && ex != -1) {
				enemy.push_back(make_pair(ey, ex));	
			}
		}
	}
	
	// vector�� ����� ���� ���� ��ǥ�� �ش� ĭ 0 && ���� �� ī��Ʈ
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
			
//	printf("���� ���� ��: %d\n", kill_count);
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
			
			// �� �� ����  
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
	} // ��ĭ(0), ��(1) 
	
	
	// �ü� ��ġ (M�� �� 3�� �̴� ����) 
	setArcher_dfs(0, 0);
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
