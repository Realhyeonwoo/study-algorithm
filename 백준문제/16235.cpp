#include<iostream> 
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct Tree {
	int alive; // death(0), live(1)
	int age;
};

int N, M, K;
int energy[11][11]; // fill�� ��� ����  ���� 
int now_energy[11][11]; // ���� ������ �ִ� ����� ���� 
vector<Tree> map[11][11]; // �� ĭ�� ���� ����
 
 bool compareAge(Tree a, Tree b) {
 	return a.age < b.age;
 }
 
int main(void) {
	// �ʱ� ��� ����  
//	memset(now_energy, 5, sizeof(now_energy));
	for(int i=1; i<=10; i++) {
		for(int j=1; j<=10; j++) {
			now_energy[i][j] = 5;
		}
	}
	
	// INPUT  
	scanf("%d %d %d", &N, &M, &K);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			scanf("%d", &energy[y][x]);
		}
	}
	for(int t=1; t<=M; t++) {
		int x, y, age;
		scanf("%d %d %d", &x, &y, &age);
		Tree tree = {1, age};
		map[x][y].push_back(tree);
	}
	
	// SIMULATION
	for(int year=1; year<=K; year++) {
		// ��
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				if(map[y][x].size() != 0) {
					sort(map[y][x].begin(), map[y][x].end(), compareAge);
				
					for(int i=0; i<map[y][x].size(); i++) {
						if(map[y][x][i].alive == 1) {
							int age = map[y][x][i].age;
							if(now_energy[y][x] < age) {
								map[y][x][i].alive = 0;
								continue;
							}
							now_energy[y][x] -= age;
							map[y][x][i].age++;	
						}
					}	
				}
			}
		}
		// ����
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				if(map[y][x].size() != 0) {
					vector<Tree> temp;
					for(int i=0; i<map[y][x].size(); i++) {
						if(map[y][x][i].alive == 1){
							temp.push_back(map[y][x][i]);
							continue;
						}
						if(map[y][x][i].alive == 0 && map[y][x][i].age != 0) {
							now_energy[y][x] += map[y][x][i].age / 2;	
							map[y][x][i].age = 0;				
						}
					}
					
					// ���� ������ �������� (�ð��ʰ��� ����) 
					map[y][x].clear();
					for(int i=0; i<temp.size(); i++) {
						map[y][x].push_back(temp[i]);
					}
					temp.clear();
				}
			}
		}
		// ����
		int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
		int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				if(map[y][x].size() != 0) {
					for(int i=0; i<map[y][x].size(); i++) {
						
						if(map[y][x][i].alive == 1 && map[y][x][i].age % 5 == 0) {
							for(int dir=0; dir<8; dir++) {
								int ny = y + dy[dir];
								int nx = x + dx[dir];
								
								if(ny<1 || ny>N || nx<1 || nx>N ) continue;
								
								Tree tree = {1, 1};
								map[ny][nx].push_back(tree);
							}
						}
					}
				}
			}
		}
		// �ܿ�	
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				now_energy[y][x] += energy[y][x];
			}
		}
	}
	
	// OUTPUT
	int count = 0; 
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=N; x++) {
			for(int i=0; i<map[y][x].size(); i++) {
				if(map[y][x][i].alive == 1) {
					count ++;
				}
			}
		}
	}
	printf("%d\n", count);
	
	return 0;
}
