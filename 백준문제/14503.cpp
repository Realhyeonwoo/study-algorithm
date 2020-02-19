#include<iostream>
using namespace std;

int N, M; // ¼¼·Î(N), °¡·Î(M) 
int robot_y, robot_x, robot_d; // ºÏ(0), µ¿(1), ³²(2), ¼­(3) 
int map[50][50];

bool checkAround() {
		
}

int main(void) {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &robot_y, &robot_x, &robot_d);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	// ºóÄ­(0), º®(1), Ã»¼Ò(2) 
	while(true) {
		bool move = false;
		// 1  
		map[robot_y][robot_x] = 2;
		
		
//		printf("=============[%d, %d] (¹æÇâ: %d)==============\n", robot_y, robot_x, robot_d);
//		for(int y=0; y<N; y++) {
//			for(int x=0; x<M; x++) {
//				printf("%d ", map[y][x]);
//			}
//			printf("\n");
//		}
//		printf("===============================\n");
		
		
		bool clean = true;
		for(int dir=0; dir<4; dir++) {
			int ny = robot_y + dy[dir];
			int nx = robot_x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(map[ny][nx]==2 || map[ny][nx]==1) continue;
			
			clean = false;
		}
		switch(robot_d) {
			case 0: // ºÏ 
				if(clean && (robot_y+1>=N || map[robot_y+1][robot_x]==1)) {
					move = true;
					break;
				} else if(clean) {
					robot_y +=1;
				} else {
					if(map[robot_y][robot_x-1] == 0) {
						robot_d = 3;
						robot_x -= 1;
					} else {
						robot_d = 3;
					}
				}
				break;
			case 1: // µ¿ 
				if(clean && (robot_x-1<0 || map[robot_y][robot_x-1]==1)) {
					move = true;
					break;
				} else if(clean) {
					robot_x -= 1;
				} else {
					if(map[robot_y-1][robot_x]== 0) {
						robot_d = 0;
						robot_y -= 1;
					} else {
						robot_d = 0;
					}
				}
				break;
			case 2: // ³² 
				if(clean && (robot_y-1<0 || map[robot_y-1][robot_x]==1)) {
					move = true;
					break;
				} else if(clean) {
					robot_y -= 1;
				} else {
					if(map[robot_y][robot_x+1] == 0) {
						robot_d = 1;
						robot_x += 1;
					} else {
						robot_d = 1;
					}
				}
				break;
			case 3: // ¼­ 
				if(clean && (robot_x+1>=M || map[robot_y][robot_x+1]==1)) {
					move = true;
					break;
				} else if(clean) {
					robot_x += 1;
				} else {
					if(map[robot_y+1][robot_x]== 0) {
						robot_d = 2;
						robot_y += 1;
					} else {
						robot_d = 2;
					}
				}
				break;
		}
		
		
		if(move) break;
	}
	
	// OUTPUT
	int count = 0;
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			if(map[y][x] == 2) count++;
		}
	}
	printf("%d\n", count);
	
	return 0;
}
