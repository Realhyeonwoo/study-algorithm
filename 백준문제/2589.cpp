#include<iostream>
using namespace std;

int N, M; // 세로(N), 가로(M)
int map[50][50];
int main(void) {
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf(" %c", &map[y][x]);
		}
	}
	
	
	return 0;
}


/*

	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			printf("%c ", map[y][x]);
		}
		printf("\n");
	}
	

*/

