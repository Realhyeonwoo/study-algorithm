#include<stdio.h>

int board[20][20];

int main(void) {
	int n, x, y; 
	
	for(int i=1; i<20; i++) {
		for(int j=1; j<20; j++) {
			scanf("%d", &board[i][j]); 
		}
	}
	
	scanf("%d", &n); 
	
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &x, &y); 
		for(int j=1; j<20; j++) {
			if(board[x][j] == 0) {
				board[x][j] = 1;
			} else {
				board[x][j] = 0;
			}
		}
		
		for(int j=1; j<20; j++) {
			if(board[j][y] == 0) {
				board[j][y] = 1;
			} else {
				board[j][y] = 0;
			}
		}
	}
	
	for(int i=1; i<20; i++) {
		for(int j=1; j<20; j++) {
			printf("%d ", board[i][j]); 
		}
		printf("\n"); 
	}
	return 0; 
}
