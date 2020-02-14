#include<iostream>
using namespace std;

int N, M; // N: 세로(y), M: 가로(x)
char map[50][50];
char eightBoard[8][8];
int minV = 99999;

char boardB[8][8];
char boardW[8][8];
void makeCorrectBoard() {
	for(int y=0; y<8; y++){
		for(int x=0; x<8; x++) {
			if((y+x) % 2 == 0) {
				boardB[y][x] = 'B';
				boardW[y][x] = 'W';
			} else {
				boardB[y][x] = 'W';
				boardW[y][x] = 'B';
			}
		}
	}
}

int checkBoard() {
	int countW = 0, countB = 0;
	
	for(int y=0; y<8; y++) {
		for(int x=0; x<8; x++) {
			if(boardB[y][x] != eightBoard[y][x]) countB++;
			if(boardW[y][x] != eightBoard[y][x]) countW++;
		}
	}
	
//	for(int y=0; y<8; y++) {
//		for(int x=0; x<8; x++) {
//			printf("%c ", eightBoard[y][x]);
//		}
//		printf("\n");
//	}
//	printf("B: %d, W: %d\n", countB, countW);
	return (countW > countB) ? countB : countW; 
}

int main(void) {
	// input
	scanf("%d %d", &N, &M);
	for(int y=0; y<N; y++) {
		for(int x=0; x<M; x++) {
			scanf("%1s", &map[y][x]);
		}  
	}
	
	// make Black && White board
	makeCorrectBoard();
	
//	printf("==== BLACK ====\n");
//	for(int y=0; y<8; y++) {
//		for(int x=0; x<8; x++) {
//			printf("%c ", boardB[y][x]);
//		}
//		printf("\n");
//	}
//	printf("==== WHITE ====\n");
//	for(int y=0; y<8; y++) {
//		for(int x=0; x<8; x++) {
//			printf("%c ", boardW[y][x]);
//		}
//		printf("\n");
//	}

	// simulation
	for(int y=0; y<=N-8; y++) {
		for(int x=0; x<=M-8; x++) {
			// make 8x8 board
			int a = 0;
			for(int i=y; i<y+8; i++) {
				int b = 0;
				for(int j=x; j<x+8; j++) {
					eightBoard[a][b] = map[i][j];	
					b++;
				}
				a++;
			}
			
			printf("=====[y: %d, x: %d]=====\n", y, x);
			for(int y=0; y<8; y++) {
				for(int x=0; x<8; x++) {
					printf("%c ", boardW[y][x]);
				}
				printf("\n");
			}
			printf("\n");
			
			//check board
			int num = checkBoard();
//			printf("num: %d\n", num);
			if(minV > num) {
				minV = num;
			}	
		}
	}
	
	// output
	printf("%d\n", minV);
	
	return 0;
}
