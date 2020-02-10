#include<iostream> 
#include<queue>
#include<utility>
#include<cstring>
using namespace std;

int R, C, T; // R:��(y), C:��(x), T:�ݺ�Ƚ��(�ð�)
int map[51][51];
int dust[51][51]; // �߰��Ǵ� dust �� 
bool visited[51][51]; // �湮���� Ȯ�� 
vector<pair<int, int> > cleaner; // ����û���� ��ġ 

void onCleaner() {
	// map clone
	int backup[51][51];
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			backup[y][x] = map[y][x];
		}
	}
	
	// get cleaner position
	pair<int, int> cur = cleaner[0];
	int cy1 = cur.first; int cx1 = cur.second;
	cur = cleaner[1];
	int cy2 = cur.first; int cx2 = cur.second;
	
	// ���� cleaner 
	for(int x=cx1; x<C; x++) {
		if(x==cx1) {
			backup[cy1][x+1] = 0;
			continue;
		}
		backup[cy1][x+1] = map[cy1][x];
	}
	for(int y=cy1; y>1; y--) {
		backup[y-1][C] = map[y][C];
	}
	for(int x=C; x>cx1; x--) {
		backup[1][x-1] = map[1][x];
	}
	for(int y=1; y<cy1; y++) {
		if(y+1 == cy1) {
			continue;
		}
		backup[y+1][1] = map[y][1];
	}
	
	// �Ʒ��� cleaner 
	for(int x=cx2; x<C; x++) {
		if(x==cx2) {
			backup[cy2][x+1] = 0;
			continue;
		}
		backup[cy2][x+1] = map[cy2][x];
	}
	for(int y=cy2; y<R; y++) {
		backup[y+1][C] = map[y][C];
	}
	for(int x=C; x>cx2; x--) {
		backup[R][x-1] = map[R][x];
	}
	for(int y=R; y>cy2; y--) {
		if(y-1 == cy2) continue;
		backup[y-1][1] = map[y][1];
	}

	// ��ȯ �� ��� ��¥ map���� ���� 
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			map[y][x] = backup[y][x];
		}
	}
}

void spreadDust() {
	memset(dust, 0, sizeof(dust));
	memset(visited, false, sizeof(visited));
	
	queue<pair<int, int> > q;
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			if(map[y][x] != 0 && map[y][x] != -1) {
				q.push(make_pair(y, x));	
			}
		}
	}	
		
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		int cy = cur.first;
		int cx = cur.second;
	
		visited[cy][cx] = true;
		
		int dy[] = {-1, 1, 0, 0};
		int dx[] = {0, 0, -1, 1};
		vector<pair<int, int> > room; 
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<1 || ny>R || nx<1 || nx>C) continue;
			if(map[ny][nx] == -1) continue;
			room.push_back(make_pair(ny, nx));
		}
		
		int spread_dust = map[cy][cx] / 5;
		map[cy][cx] -= spread_dust * room.size();
		for(int i=0; i<room.size(); i++) {
			dust[room[i].first][room[i].second] += spread_dust;
		}
	}
	
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			if(dust[y][x] != 0) {
				map[y][x] += dust[y][x];
			}
		}
	}
}

int main(void) {
	// �Է� 
	scanf("%d %d %d", &R, &C, &T);
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			scanf("%d", &map[y][x]);
			if(map[y][x] == -1) cleaner.push_back(make_pair(y, x));
		}
	}
	
	// T�� ����  
	for(int time=1; time<= T; time++) {
		// ���� Ȯ�� (��� ĭ ���ÿ�)
		spreadDust();	
		// ����û���� �۵�  
		onCleaner();
	}
	
	// ���� �̼����� ���� �� 
	int sum = 0; 
	for(int y=1; y<=R; y++) {
		for(int x=1; x<=C; x++) {
			if(map[y][x] != -1) {
				sum += map[y][x];	
			}
		}
	}
	printf("%d\n", sum);
	
	return 0;	
}
