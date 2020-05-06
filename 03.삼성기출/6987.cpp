// boj-6987
#include<iostream>
using namespace std; 

int map[4][18];
int answer[4];

int main(void) {
	for(int y=0; y<4; y++) {
		int win = 0, lose = 0;
		for(int x=0; x<18; x++) {
			scanf("%d", &map[y][x]);
			if(x%3 ==0) win += map[y][x];
			else lose += map[y][x];
		}
		if(win == lose) answer[y] = 1;
	}
	
	for(int i=0; i<4; i++) printf("%d ", answer[i]);
	printf("\n");
	return 0;
}
