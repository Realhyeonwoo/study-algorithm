#include<iostream>
#include<cstring>
using namespace std;

int N, M, K;
int map[41][41];
int backup[41][41];
int sy, sx;
int sticker[11][11];

void copyMap(int num) {
	if(num == 1) {
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=M; x++) {
				backup[y][x] = map[y][x]; 
			}
		}
	} else {
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=M; x++) {
				map[y][x] = backup[y][x];
			}
		}
	}
}

bool putSticker() {
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=M; x++) {
			if(N-sy+1>=y && M-sx+1>=x) {
				bool flag = false;
				memset(backup, 0, sizeof(backup));
				copyMap(1);
				for(int i=1; i<=sy; i++) {
					for(int j=1; j<=sx; j++) {
						if(sticker[i][j] == 1) {
							if(map[y+i-1][x+j-1] == 1)  {
								flag = true;
								break;	
							} else {
								backup[y+i-1][x+j-1] = sticker[i][j];	
							}
						} 
					}
					if(flag) break;
				}
				if(!flag) {
					copyMap(2);
					return true;					
				}
			}
		}
	}
	return false;
}

void rotateSticker(void) {
	memset(backup, 0, sizeof(backup));
	int temp;
	for(int y=1; y<=sy; y++) {
		for(int x=1; x<=sx; x++) {
			backup[x][sy-y+1] = sticker[y][x];
		}
	}
	
	// sy sx 정보도 변경해줘야 함  
	temp = sy;
	sy = sx;
	sx = temp;	
	
	memset(sticker, 0, sizeof(sticker));
	for(int y=1; y<=sy; y++) {
		for(int x=1; x<=sx; x++) {
			sticker[y][x] = backup[y][x]; 
		}
	}
}

int main(void) {
	// INPUT
	scanf("%d %d %d", &N, &M, &K);
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=M; x++) {
			map[y][x] = 0;
		}
	}
	
	// SIMULATION
	for(int i=1; i<=K; i++) {
		// 스티커 정보 입력 
		scanf("%d %d", &sy, &sx);
		for(int y=1; y<=sy; y++) {
			for(int x=1; x<=sx; x++) {
				scanf("%d", &sticker[y][x]);
			}
		}
		// 90, 180, 270 회전(중간 탈출 가능)
		for(int r=1; r<=4; r++)  {
			if(N >= sy && M >= sx && putSticker()) break;
			rotateSticker();
		}
	}
	
	// OUTPUT
	int answer = 0;
	for(int y=1; y<=N; y++) {
		for(int x=1; x<=M; x++) {
			if(map[y][x] == 1) answer ++;
		}
	}
	printf("%d\n", answer);
	
	return 0;
	
}
