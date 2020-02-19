#include<iostream>
#include<cstring> 
using namespace std;

int R, C, M; // 행(R), 열(C), 상어의 수(M)
int map[101][101][4]; // 1 ~ 100, 상어존재유무(0), 속도(1) 방향(2) 크기(3)
					  // 방향: 위(1), 아래(2), 오른쪽(3), 왼쪽(4) 
int copyMap[101][101][4];

int catchShark(int fisher) {
	int fish = 0;
	for(int y=1; y<=R; y++)	 {
		if(map[y][fisher][0] == 1) {
			map[y][fisher][0] = 0;
			return map[y][fisher][3];
		}
	}
	return 0;
}

void moveShark() {
	// MOVE
	for(int y=1; y<=R; y++)	 {
		for(int x=1; x<=C; x++) {
			if(map[y][x][0] == 1) { // 상어라면  
				int shark_speed = map[y][x][1]; 
				int shark_direction = map[y][x][2];
				int shark_size = map[y][x][3];
				int shark_y = y, shark_x = x;
				int turn = shark_speed;
				while(turn>0) {
					int ny = 0, nx = 0;
					switch(shark_direction) {
						case 1: // 위 
							ny = shark_y - 1;
							if(ny <= 0) {
								shark_direction = 2;
								shark_y = 2;
								break;
							}
							shark_y = ny;
							break;
						case 2: // 아래 
							ny = shark_y + 1;
							if(ny > R) {
								shark_direction = 1;
								shark_y = R-1;
								break;
							}
							shark_y = ny;
							break;
						case 3: // 오 
							nx = shark_x + 1;
							if(nx > C) {
								shark_direction = 4;
								shark_x = C-1;
								break;
							}
							shark_x = nx;
							break;
						case 4: // 왼 
							nx = shark_x - 1;
							if(nx <= 0) {
								shark_direction = 3;
								shark_x = 2;
								break;
							}
							shark_x = nx;
							break;
					}	
					turn--;				
				}
				// 이동완료한 상어 저장
				if(copyMap[shark_y][shark_x][0] == 1) { // 이미 상어가 있는 경우 
					if(copyMap[shark_y][shark_x][3] < shark_size) { // 큰 사이즈의 상어가 들어 
						copyMap[shark_y][shark_x][1] = shark_speed;
						copyMap[shark_y][shark_x][2] = shark_direction;
						copyMap[shark_y][shark_x][3] = shark_size;	
					}
				} else {
					copyMap[shark_y][shark_x][0] = 1;
					copyMap[shark_y][shark_x][1] = shark_speed;
					copyMap[shark_y][shark_x][2] = shark_direction;
					copyMap[shark_y][shark_x][3] = shark_size;	
				}	
			}
		}
	}
	
	// 이동 후 위치 원래 map에 복사 가 
	memset(map, 0, sizeof(map));
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			for(int i=0; i<4; i++) {
				map[y][x][i] = copyMap[y][x][i];
			}
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &R, &C, &M);
	for(int i=1; i<=M; i++) {
		int r, c, s, d, z; // 세로(r), 가로(c), 속도(s), 방향(d), 크기(z) 
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		map[r][c][0] = 1;
		map[r][c][1] = s;
		map[r][c][2] = d;
		map[r][c][3] = z;
	}
	
	
	// SIMULATION 
	int answer = 0;
	if(M == 0) {
		printf("%d\n", answer);
		return 0;
	}
	for(int move=1; move<=C; move++) {
		answer += catchShark(move);
		memset(copyMap, 0, sizeof(copyMap));
		moveShark();
	}
	
	// OUTPUT
	printf("%d\n", answer);
	return 0;
}
