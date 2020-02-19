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
		// 1  
		map[robot_y][robot_x] = 2;
		
		switch(robot_d) {
			case 0: // ºÏ 
				break;
			case 1: // µ¿ 
				break;
			case 2: // ¼­ 
				break;
			case 3: // ³² 
				break;
		}
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
