#include<iostream>
#include<cstring>
using namespace std;

int N, B; // N: 맵의 크기 (1부터 시작), B: 기지국 수 
int map[51][51]; // 1 ~ 50

int dy[] = {-1, 1, 0, 0, -2, 2, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0, -2, 2};

void spread(int y, int x) {
	for(int dir=0; dir<8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		
		if(ny<1 || ny>N || nx<1 || nx>N) continue;
		if(map[ny][nx] == -1) continue;
		int plus = map[y][x] * -1;
		map[ny][nx] += plus;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(map, 0, sizeof(map));
		
		scanf("%d %d", &N, &B);
		for(int i=0; i<B; i++) {
			int y, x;
			scanf("%d %d", &y, &x);
			map[y][x] -= 1;
		}
		
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				if(map[y][x] < 0) {
					spread(y, x); 	
				}
			}
		}

		int answer = -9999;
		for(int y=1; y<=N; y++) {
			for(int x=1; x<=N; x++) {
				if(map[y][x] > answer) {
					answer = map[y][x];
				}
			}
		}
		
		printf("#%d %d\n", test_case, answer);
		
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
