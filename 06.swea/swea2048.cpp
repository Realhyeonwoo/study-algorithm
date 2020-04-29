#include<iostream>
#include<string>
#include<cstring>
#define MAX 20
using namespace std;

int N, map[MAX][MAX];
string str;

void doUp(void){
	for(int x=0; x<N; x++) {
		for(int y=0; y<N; y++) {
			if(map[y][x] == 0) {
				for(int z=y+1; z<N; z++) {
					if(map[z][x] != 0) {
						map[y][x] = map[z][x];
						map[z][x] = 0;
						break;
					}
				}
			}
		}
	}
	
	for(int x=0; x<N; x++) {
		for(int y=0; y<N-1; y++) {
			if(map[y][x] == map[y+1][x]) {
				map[y][x] *=2;
				map[y+1][x] = 0;
			}
		}
	}
	
	for(int x=0; x<N; x++) {
		for(int y=0; y<N; y++) {
			if(map[y][x] == 0) {
				for(int z=y+1; z<N; z++) {
					if(map[z][x] != 0) {
						map[y][x] = map[z][x];
						map[z][x] = 0;
						break;
					}
				}
			}
		}
	}
}
void doDown(void){
	for(int x=0; x<N; x++) {
		for(int y=N-1; y>=0; y--) {
			if(map[y][x] == 0) {
				for(int z=y-1; z>=0; z--) {
					if(map[z][x] != 0) {
						map[y][x] = map[z][x];
						map[z][x] = 0;
						break;
					}
				}
			}
		}
	}
	
	for(int x=0; x<N; x++) {
		for(int y=N; y>0; y--) {
			if(map[y][x] == map[y-1][x]) {
				map[y][x] *=2;
				map[y-1][x] = 0;
			}
		}
	}
	
	for(int x=0; x<N; x++) {
		for(int y=N-1; y>=0; y--) {
			if(map[y][x] == 0) {
				for(int z=y-1; z>=0; z--) {
					if(map[z][x] != 0) {
						map[y][x] = map[z][x];
						map[z][x] = 0;
						break;
					}
				}
			}
		}
	}
}

void doLeft(void){
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == 0) {
				for(int z=x+1; z<N; z++) {
					if(map[y][z] != 0) {
						map[y][x] = map[y][z];
						map[y][z] = 0;
						break;
					}
				}
			}
		}
	}
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<N-1; x++) {
			if(map[y][x] == map[y][x+1]) {
				map[y][x] *=2;
				map[y][x+1] = 0;
			}
		}
	}
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] == 0) {
				for(int z=x+1; z<N; z++) {
					if(map[y][z] != 0) {
						map[y][x] = map[y][z];
						map[y][z] = 0;
						break;
					}
				}
			}
		}
	}
}

void doRight(void){
	for(int y=0; y<N; y++) {
		for(int x=N-1; x>=0; x--) {
			if(map[y][x] == 0) {
				for(int z=x-1; z>=0; z--) {
					if(map[y][z] != 0) {
						map[y][x] = map[y][z];
						map[y][z] = 0;
						break;
					}
				}
			}
		}
	}
	
	for(int y=0; y<N; y++) {
		for(int x=N; x>0; x--) {
			if(map[y][x] == map[y][x-1]) {
				map[y][x] *=2;
				map[y][x-1] = 0;
			}
		}
	}
	
	for(int y=0; y<N; y++) {
		for(int x=N-1; x>=0; x--) {
			if(map[y][x] == 0) {
				for(int z=x-1; z>=0; z--) {
					if(map[y][z] != 0) {
						map[y][x] = map[y][z];
						map[y][z] = 0;
						break;
					}
				}
			}
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		// INIT
		str.clear();
		memset(map, 0, sizeof(map));
		
		// INPUT
		cin >> N >> str;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				scanf("%d", &map[y][x]);
			}
		}
		
		// SIMULATION
		if(str == "up") doUp();
		else if(str == "down") doDown();
		else if(str == "left") doLeft();
		else if(str == "right") doRight();
		
		// OUTPUT
		printf("#%d\n", tc);
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				printf("%d ", map[y][x]);
			}
			printf("\n");
		}
	}
	return 0;
}
