#include<stdio.h>

int miro[11][11]; 

int main(void) {
	// 입력받기
	for(int i=1; i<11; i++) {
		for(int j=1; j<11; j++) {
			scanf("%d", &miro[i][j]);
		}
	}
	
	int x = 2, y = 2; 
	
	while(1) {
		miro[x][y] = 9; 
		
		if(miro[x][y+1] != 1) {
			if(miro[x][y+1] == 2){
				miro[x][y+1] = 9; 
				break;	
			} 
			miro[x][y+1] = 9; 
			y++;
		} else {
			if(miro[x+1][y] == 2) {
				miro[x+1][y] = 9; 
				break;
			}
			miro[x+1][y] = 9; 
			x++;
		}
	}
	
	for(int i=1; i<11; i++) {
		for(int j=1; j<11; j++) {
			printf("%d ", miro[i][j]); 
		}
		printf("\n"); 
	}
	return 0; 
}
