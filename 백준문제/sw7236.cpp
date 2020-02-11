#include<iostream>
#include<cstring>
using namespace std;

int N;
int map[100][100];
int value[100][100];

int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};

void check(int y, int x) {
	int count = 0;
	
	for(int dir=0; dir<8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
		if(map[ny][nx] == 'W') {
			count++;
		}
	}
	
	if(count == 0) {
		count = 1;
	}
	
	value[y][x] = count;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(value, 0, sizeof(value));
		
		scanf("%d", &N);
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				scanf("%1s", &map[y][x]);
			}
		}
		
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				check(y, x);
			}
		}
		
		
		int answer = -99999;
		for(int y=0; y<N; y++) {
			for(int x=0; x<N; x++) {
				if(value[y][x] > answer) {
					answer = value[y][x];
				}
			}
		}
		
		
		printf("#%d %d\n", test_case, answer);
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
