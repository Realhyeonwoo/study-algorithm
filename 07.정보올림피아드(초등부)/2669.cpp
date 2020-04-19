#include<iostream>
#define MAX 100
using namespace std;

int map[MAX][MAX];
int answer = 0;

int main(void) {
	int x1, y1, x2, y2;
	for(int i=1; i<=4; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		for(int y=y1; y<=y2-1; y++) {
			for(int x=x1; x<=x2-1; x++) {
				if(map[y][x] == 0) {
					answer++;
					map[y][x] = 1;
				}
			}
		}
	}
	
	printf("%d\n", answer);
	
	return 0;
}
