#include<stdio.h>

/*
	h: ������ ����  
	w: ������ ����
	
	l: �� ������ ����
	d: ���븦 ���� ����(����: 0, ����: 1) 
	(x, y): ���븦 ���� ������  
*/

int board[101][101];
 
int main(void) {
	int h, w, l , d, x, y, n; 
	
	scanf("%d %d", &h, &w); 
	scanf("%d", &n); 
	
	while(n--) {
		scanf("%d %d %d %d", &l, &d, &x, &y); 
		
			switch(d) {
				case 0:
					for(int i=0; i<l; i++) {
						board[x][y++] = 1; 
					}
					break;
				case 1:
					for(int i=0; i<l; i++) {
						board[x++][y] = 1; 
					}
					break;
			}
		
	}
	
	for(int i=1; i<=h; i++) {
		for(int j=1; j<=w; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n"); 
	}
	return 0; 
}
