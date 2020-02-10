#include<iostream>
using namespace std;

int R, C; // R:За(y), C:ї­(x)
char map[250][250];
bool visited[250][250] = {false, };
int sheep = 0, wolf = 0;
int answerSheep = 0, answerWolf = 0;

void dfs(int y, int x){
	if(!visited[y][x] && map[y][x] == 'v') wolf++;
	if(!visited[y][x] && map[y][x] == 'o') sheep++;
	visited[y][x] = true;
	
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
		if(visited[ny][nx] || map[ny][nx] == '#') continue;
		dfs(ny, nx);
	}
}

int main(void) {
	scanf("%d %d", &R, &C);
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			scanf("%1s", &map[y][x]);
		}
	}
	
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			if(!visited[y][x] && map[y][x] != '#') {
				sheep = 0; wolf = 0;
				dfs(y, x);
				
				if(sheep!=0 || wolf!=0) {
					if(sheep > wolf) {
						wolf = 0;
					} else {
						sheep = 0;
					}	
				}				
				answerSheep += sheep;
				answerWolf += wolf;
			}
		}
	 }
	
	printf("%d %d", answerSheep, answerWolf);

	return 0;
}
