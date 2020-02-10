#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;


int map[5][5][5];
int backup[5][4][5][5]; // 5개의 판종류를 4방향으로 돌린 판 4개를  [5][5]판에 하나씩 저장 
int miro[5][5][5]; // 완성된 3차원 미로 
bool visited[5][5][5];
int value[5][5][5];
vector<int> answer;

struct Point {
	int h, y, x;
};

// 탐색 시작 
void miro_bfs(int start_h, int start_y, int start_x, int end_h, int end_y, int end_x) {
	memset(visited, false, sizeof(visited));
	memset(value, 0, sizeof(value));
	
	queue<Point> q;
	Point point = {start_h, start_y, start_x};
	q.push(point);
	visited[start_h][start_y][start_x] = true;
	
	while(!q.empty()) {
		Point cur = q.front();
		q.pop();
		
		int ch = cur.h;
		int cy = cur.y;
		int cx = cur.x;
		
		if(end_h == ch && end_y == cy && end_x == cx) {
//			printf("[%d %d %d](value: %d)(visited: %d)\n", ch, cy, cx, value[ch][cy][cx], visited[ch][cy][cx]);
			answer.push_back(value[ch][cy][cx]);
//			break;	
		}
		
		int dh[] = {0, 0, 0, 0, -1, 1};
		int dy[] = {-1, 1, 0, 0, 0, 0};
		int dx[] = {0, 0, -1, 1, 0, 0};
		for(int dir=0; dir<6; dir++) {
			int nh = ch + dh[dir];
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(nh<0 || nh>=5 || ny<0 || ny>=5 || nx<0 || nx>=5) continue;
			if(visited[nh][ny][nx]) continue;
			if(miro[nh][ny][nx] == 0) continue;
			if(value[nh][ny][nx] != 0) continue;
			
			visited[nh][ny][nx] = true;
			value[nh][ny][nx] += value[ch][cy][cx] + 1;
			Point np = {nh, ny, nx};
			q.push(np);
		}
	}	
}

// 0번~4번 판 => 기본 + 시계방향 90도씩 3번  
void spinBoard(int h, int spin) {
	switch(spin) {
		case 0:
			for(int y=0; y<5; y++) {
				for(int x=0; x<5; x++) {
					backup[h][spin][y][x] = map[h][y][x];
				}
			}
			break;
		case 1:
			for(int y=0; y<5; y++) {
				for(int x=0; x<5; x++) {
					backup[h][spin][y][x] = map[h][4-x][y];
				}
			}
			break;
		case 2: 
			for(int y=0; y<5; y++) {
				for(int x=0; x<5; x++) {
					backup[h][spin][y][x] = backup[h][1][4-x][y];
				}
			}
			break;
		case 3:
			for(int y=0; y<5; y++) {
				for(int x=0; x<5; x++) {
					backup[h][spin][y][x] = backup[h][2][4-x][y];
				}
			}
			break;
	}
}

int main(void) {
	// 0: 들어갈 수 없는 칸, 1: 들어갈 수 있는 칸 
	for(int h=0; h<5; h++) {
		for(int y=0; y<5; y++) {
			for(int x=0; x<5; x++) {
				scanf("%d", &map[h][y][x]);
			}
		}
	}
	// 돌려져서 나오는 판 저장  
	for(int h=0; h<5; h++) {
		for(int spin=0; spin<4; spin++) {
			spinBoard(h, spin);
		}
	}
	// 3차원 미로생성(4의 5승) 
	int board[5][5][5]; 
	for(int i=0; i<4; i++) {
		for(int y=0; y<5; y++) {
			for(int x=0; x<5; x++) {
				board[0][y][x] = backup[0][i][y][x];
			}
		}
		for(int j=0; j<4; j++) {
			for(int y=0; y<5; y++) {
				for(int x=0; x<5; x++) {
					board[1][y][x] = backup[1][j][y][x];
				}
			}
			for(int k=0; k<4; k++) {
				for(int y=0; y<5; y++) {
					for(int x=0; x<5; x++) {
						board[2][y][x] = backup[2][k][y][x];
					}
				}
				for(int l=0; l<4; l++) {
					for(int y=0; y<5; y++) {
						for(int x=0; x<5; x++) {
							board[3][y][x] = backup[3][l][y][x];
						}
					}
					for(int m=0; m<4; m++) {
						for(int y=0; y<5; y++) {
							for(int x=0; x<5; x++) {
								board[4][y][x] = backup[4][m][y][x];
							}
						}	
						
						for(int h1=0; h1<5; h1++) {
							for(int h2=0; h2<5; h2++) {
								if(h2 == h1) continue;
								for(int h3=0; h3<5; h3++) {
									if(h3 == h1 || h3 == h2) continue;
									for(int h4=0; h4<5; h4++) {
										if(h4 == h1 || h4 == h2 || h4 == h3) continue;
										for(int h5=0; h5<5; h5++) {
											if(h5 == h1 || h5 == h2 || h5 == h3 || h5 == h4) continue;	
											for(int y=0; y<5; y++) {
												for(int x=0; x<5; x++) {
													miro[0][y][x] = board[h1][y][x];				
													miro[1][y][x] = board[h2][y][x];				
													miro[2][y][x] = board[h3][y][x];				
													miro[3][y][x] = board[h4][y][x];				
													miro[4][y][x] = board[h5][y][x];						
												}
											}
											
											if(miro[0][0][0] == 1 && miro[4][4][4] == 1) {
												miro_bfs(0, 0, 0, 4, 4, 4);	
											} 
										}
									}
								}
							}
						}	
					}
				}
			}
		}
	}
	
	if(answer.size() == 0) {
		printf("-1\n");
	} else {
		sort(answer.begin(), answer.end());
		printf("%d\n", answer[0]);
	}
	
	return 0;
}
