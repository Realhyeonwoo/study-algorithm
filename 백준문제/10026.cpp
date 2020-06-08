//#include<iostream>
//#include<cstring>
//#include<queue>
//#include<utility>
//using namespace std;
//
//int n;
//int map[100][100];
//int copyMap[100][100];
//bool visited[100][100] = {false, };
//
//void bfs(int y, int x, int color) {
////	printf("color: %d\n", color);
//	queue< pair<int, int> > q;
//	q.push(make_pair(y, x));
//	
//	while(!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//		int cx = cur.first;
//		int cy = cur.second;
//		
//		visited[cy][cx] = true;
//		copyMap[cy][cx] = 0;
//		
////		printf("\n\n");
////		for(int y=0; y<n; y++) {
////			for(int x=0; x<n; x++) {
////				printf("%d ", copyMap[y][x]);
////			}
////			printf("\n");
////		}	
////		printf("\n\n");
//		
//		int dy[] = {-1, 1, 0, 0};
//		int dx[] = {0, 0, -1, 1};
//		for(int dir=0; dir<4; dir++) {
//			int ny = cy + dy[dir];
//			int nx = cx + dx[dir];
//			
//			if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
////			printf("%d \n", copyMap[ny][nx]);
//			if(copyMap[ny][nx] != color || visited[ny][nx])continue;
////			printf("q¿¡Ãß°¡: [%d, %d]\n", ny, nx);
//			q.push(make_pair(ny, nx));
//		}
//	}
//}
//
//int main(void) {
//	scanf("%d", &n);
//	char temp;
//	for(int y=0; y<n; y++) {
//		for(int x=0; x<n; x++) {
//			scanf("%1s", &temp);
//			if(temp == 'R') {
//				map[y][x] = 1;
//			} else if(temp == 'G') {
//				map[y][x] = 2;
//			} else {
//				map[y][x] = 3;
//			}
//		}
//	}
//	// R:1, G:2, B:3	
//	for(int y=0; y<n; y++) {
//		for(int x=0; x<n; x++) {
//			copyMap[y][x] = map[y][x];
//		}
//	}
//	
//	int count = 0; 
//	for(int y=0; y<n; y++) {
//		for(int x=0; x<n; x++) {
//			if(copyMap[y][x] != 0) {
//				count++;
//				bfs(y, x, copyMap[y][x]);
//			}
//		}
//	}	
//	
//	printf("%d\n", count);
//	return 0; 
//}

#include<iostream>
#include<string>
#include<queue>
#define MAX 100
using namespace std;

int N;
char map[MAX][MAX], map2[MAX][MAX];
int Answer1, Answer2;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(int a, int b, char map[][MAX], char ch) {
	queue<pair<int, int> > Q;
	Q.push(make_pair(a, b));
	map[a][b] = 'x';
	
	while(!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
			if(map[ny][nx] == 'x') continue;
			
			if(map[ny][nx] == ch) {
				Q.push(make_pair(ny, nx));
				map[ny][nx] = 'x';
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// INPUT
	cin >> N;
	string str;
	for(int y=0; y<N; y++)	{
		cin >> str;
		for(int x=0; x<N; x++) {
			map[y][x] = str[x];
			map2[y][x] = str[x];
			if(str[x] == 'G') map2[y][x] = 'R';
		}
	}
	
	// SIMULATION
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map[y][x] != 'x') {
				bfs(y, x, map, map[y][x]);
				Answer1++;
			}	
		}
	}
	
	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			if(map2[y][x] != 'x') {
				bfs(y, x, map2, map2[y][x]);	
				Answer2++;		
			}
		}
	}
	
	// OUTPUT
	cout << Answer1 << ' ' << Answer2 << '\n';
	
	return 0;
}
