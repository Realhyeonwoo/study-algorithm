#include<iostream>
using namespace std;

int R, C, M; // ��(R), ��(C), ����� ��(M)
int map[101][101][4]; // 1 ~ 100, �����������(0), �ӵ�(1) ����(2) ũ��(3)
					  // ����: ��(1), �Ʒ�(2), ������(3), ����(4) 
int copyMap[101][101][4];

int catchShark(int fisher) {
	int fish = 0;
	for(int y=1; y<=R; y++)	 {
		if(map[y][fisher][0] == 1) {
			map[y][fisher][0] = 0;
			fish++;
		}
	}
	return fish;
}

void moveShark() {
	// COPY
	for(int y=1; y<=R; y++)	 {
		for(int x=1; x<=C; x++) {
			if(map[y][x][0] == 1) {
				int shark_y = map[y][x][1];
				int shark_x = map[y][x][2];
				int shark_speed = map[y][x][3];
				int shark_size = map[y][x][5];
			}
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &R, &C, &M);
	for(int i=1; i<=M; i++) {
		int r, c, s, d, z; // ����(r), ����(c), �ӵ�(s), ����(d), ũ��(z) 
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		map[r][c][0] = 1;
		map[r][c][1] = s;
		map[r][c][2] = d;
		map[r][c][3] = z;
	}
	
	// SIMULATION 
	int answer = 0;
	for(int move=1; move<=C; move++) {
		answer += catchShark(move);
		memset(copyMap, 0, sizeof(copyMap));
		moveShark();
	}
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
