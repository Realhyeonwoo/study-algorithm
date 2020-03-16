#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int T, N, W, H;
int map[16][13];
int backup[16][13];
vector<int> ball;
int answer;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void copyMap(int num) {
	if(num == 1) {
		for(int y=1; y<=H; y++) {
			for(int x=1; x<=W; x++) {
				backup[y][x] = map[y][x];
			}
		}
	} else if(num == 2){
		for(int y=1; y<=H; y++) {
			for(int x=1; x<=W; x++) {
				map[y][x] = backup[y][x];
			}
		}
	}
}

int checkBlock() {
	int count = 0;
	for(int y=1; y<=H; y++) {
		for(int x=1; x<=W; x++) {
			if(map[y][x] != 0) count++;
		}
	}
	return count;
}

void moveBlock() {
	for(int y=H-1; y>=1; y--) {
		for(int x=1; x<=W; x++) {
			int temp = y;
			if(map[temp][x] != 0) {
				while(1) {
					if(temp == H || map[temp+1][x] != 0) break;
							
					map[temp+1][x] = map[temp][x];
					map[temp][x] = 0;
					temp++;
				}
			}
		}
	}
}

void destroyBlock(int y, int x, int value) {
	queue<pair<pair<int, int>, int> > q;
	map[y][x] = 0;
	q.push(make_pair(make_pair(y, x), value));
	
	while(!q.empty()) {
			int cy = q.front().first.first;
			int cx = q.front().first.second;
			int cnt = q.front().second;
			q.pop();
			
			for(int v=1; v<=cnt; v++) {
				for(int dir=0; dir<4; dir++) {
					int ny = cy + dy[dir] * v;
					int nx = cx + dx[dir] * v;
					
					if(ny<1 || ny>H || nx<1 || nx>W) continue;
					if(map[ny][nx] == 0) continue;
					if(map[ny][nx] > 1) {
						q.push(make_pair(make_pair(ny, nx), map[ny][nx]-1));	
					}
					map[ny][nx] = 0;
				}			
			}			
	}
}

void dropBall() {
	for(int i=0; i<ball.size(); i++) {
		int x = ball[i];
		for(int y=1; y<=H; y++) {
			if(map[y][x] != 0) {
				destroyBlock(y, x, map[y][x] - 1); // �� �ı� 
				moveBlock(); // �� �̵� 
				break;
			}
		}
	}
}

void pickFallingPosition(int cnt) {
	if(cnt == N) {
		copyMap(1);
		// 2. ����߷��� �� simulation
		dropBall();		
		// 3. ���� ���� �� �ּڰ� ���ϱ� (���� ���� ��)  
		answer = min(answer, checkBlock());
	
		copyMap(2);
		return;
	}	
	
	for(int i=1; i<=W; i++) {
		ball.push_back(i);
		pickFallingPosition(cnt + 1);
		ball.pop_back();
	}
}

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		answer = 987654321;
		ball.clear();
		
		//INPUT
		scanf("%d %d %d", &N, &W, &H);
		for(int y=1; y<=H; y++) {
			for(int x=1; x<=W; x++) {
				scanf("%d", &map[y][x]);
			}
		}

		// SIMULATION
		pickFallingPosition(0); 	// 1. ���� ����߸��� (W �� �߿� N�� ���� => ����) 
			
		// OUTPUT
		printf("#%d %d\n", test_case, answer);
	}
}
