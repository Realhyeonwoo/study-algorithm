#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int R, C;
char map[21][21]; // 1 ~ 20
bool Alphabet[26];
int answer;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int y, int x, int cnt) {
	answer = max(answer, cnt);
	
	for(int dir=0; dir<4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<1 || ny>R || nx<1 || nx>C) continue;
		if(Alphabet[map[ny][nx] - 'A']) continue;
		
		Alphabet[map[ny][nx] - 'A'] = true;
		dfs(ny, nx, cnt+1);
		Alphabet[map[ny][nx] - 'A'] = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		// RESET
		memset(Alphabet, false, sizeof(Alphabet));
		answer = 0;
		
		// INPUT
		scanf("%d %d", &R, &C);
		for(int y=1; y<=R; y++) {
			for(int x=1; x<=C; x++) {
				scanf(" %c", &map[y][x]);
			}
		}
		
		// SIMULATION
		Alphabet[map[1][1] - 'A'] = true;
		dfs(1, 1, 1);
		
		// OUTPUT
		printf("#%d %d\n", test_case, answer);
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
