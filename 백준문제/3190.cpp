#include<iostream>
using namespace std;

int N; // size of BOARD ( 2 <=N<= 100)
int map[101][101]; // 1 ~ 100
int K; // number of apple
int L; // number of order

int size = 1;
int main(void) {
	scanf("%d", &N);
	scanf("%d", &K);        
	for(int i=0; i<K; i++) {
		int apple_y, apple_x;
		scanf("%d %d", &apple_y, &apple_x);
		map[apple_y][apple_x] = 5;
	}
	scanf("%d", &L);
	int time = 0;
	int y = 1, x = 1;
	map[y][x] = 1;
	int goY = 0, goX = 1;
	for(int i=0; i<L; i++) {
		int X;
		char C; // L:왼쪽, D:오른쪽 
		// 게임 시작 시간으로부터 X초가 끝난 뒤에 C방향으로 90도 회전 
		scanf("%d %c", X, C);
		while(true) {
			if((y+goY))
			else if(map[y+goY][x+goX] == 5) {
				map[y+goY][x+goX] = 1;
				size++;
			} else {
				map[y][x] = 0;
				for(int i=0; i<size; i++) {
					map[y+goY][x+goX] = 1;	
				}
			}
		
			time++;
			if(X == time) {
				break;
			}
		}
		
		
	}
}
