//#include<iostream>
//#include<queue>
// 
//#define endl "\n"
//#define MAX 1000
//using namespace std;
// 
//int R, C;
//char MAP[MAX][MAX];
//int Fire_MAP[MAX][MAX];
//bool Visit[MAX][MAX];
// 
//pair<int, int> Start, Fire;
// 
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
// 
//queue<pair<int, int > > Fire_Q;
// 
//void Input()
//{
//    cin >> R >> C;
//    for (int i = 0; i < R; i++)
//    {
//        for (int j = 0; j < C; j++)
//        {
//            bool Fire = false;
//            cin >> MAP[i][j];
//            if (MAP[i][j] == 'J')
//            {
//                Start.first = i;
//                Start.second = j;
//            }
//            else if (MAP[i][j] == 'F')
//            {
//                Fire_Q.push(make_pair(i, j));
//                Fire_MAP[i][j] = 0;
//                Fire = true;
//            }
//            if(Fire == false) Fire_MAP[i][j] = 987654321;
//        }
//    }
//}
// 
//void Make_Fire_Map(int a, int b)
//{
//    while (Fire_Q.empty() == 0)
//    {
//        int Qs = Fire_Q.size();
//        for (int s = 0; s < Qs; s++)
//        {
//            int x = Fire_Q.front().first;
//            int y = Fire_Q.front().second;
//            Fire_Q.pop();
// 
//            for (int i = 0; i < 4; i++)
//            {
//                int nx = x + dx[i];
//                int ny = y + dy[i];
// 
//                if (nx >= 0 && ny >= 0 && nx < R && ny < C)
//                {
//                    if (MAP[nx][ny] != '#')
//                    {
//                        if (Fire_MAP[nx][ny] > Fire_MAP[x][y] + 1)
//                        {
//                            Fire_MAP[nx][ny] = Fire_MAP[x][y] + 1;
//                            Fire_Q.push(make_pair(nx, ny));
//                        }
//                    }
//                }
//            }
//        }
//    }
//}
// 
//int Move_Person(int a, int b)
//{
//    queue<pair<pair<int, int>, int > > Q;
//    Q.push(make_pair(make_pair(a, b), 0));
//    Visit[a][b] = true;
// 
//    while (Q.empty() == 0)
//    {
//        int x = Q.front().first.first;
//        int y = Q.front().first.second;
//        int Cnt = Q.front().second;
//        Q.pop();
// 
//        if (x == 0 || y == 0 || x == R - 1 || y == C - 1) return Cnt + 1;
// 
//        for (int i = 0; i < 4; i++)
//        {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
// 
//            if (nx >= 0 && ny >= 0 && nx < R && ny < C)
//            {
//                if (MAP[nx][ny] != '#' && Visit[nx][ny] == false)
//                {
//                    if (Fire_MAP[nx][ny] > Cnt + 1)
//                    {
//                        Visit[nx][ny] = true;
//                        Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
//                    }
//                }
//            }
//        }
//    }
//    return -1;
//}
// 
//void Solution()
//{
//    Make_Fire_Map(Fire.first, Fire.second);
//    printf("\n");
//    for(int y=0; y<R; y++) {
//    	for(int x=0; x<C; x++) {
//    		printf("%d ", Fire_MAP[y][x]);
//		}
//		printf("\n");
//	}
//    
//    int R = Move_Person(Start.first, Start.second);
//    if (R == -1) cout << "IMPOSSIBLE" << endl;
//    else cout << R << endl;
//}
// 
//void Solve()
//{
//    Input();
//    Solution();
//}
// 
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
// 
//    //freopen("Input.txt", "r", stdin);
//    Solve();
// 
//    return 0;
//}
//


#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int R, C;
char map[1000][1000];
int fireMap[1000][1000];
bool visited[1000][1000];

pair<int, int> start, fire;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<pair<int, int> > fireTime;
void spreadFire(void) {
	while(!fireTime.empty()) {
		int cy = fireTime.front().first;
		int cx = fireTime.front().second;
		fireTime.pop();
		
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(map[ny][nx] == '#') continue;
			if(fireMap[ny][nx] <= fireMap[cy][cx] + 1) continue;
			
			fireMap[ny][nx] = fireMap[cy][cx] + 1;
			fireTime.push(make_pair(ny, nx));
		}
	}
}

int movePerson(void) {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(start.first, start.second), 0));
	visited[start.first][start.second] = true;
	
	while(!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int moveTime = q.front().second;
		q.pop();
		
		if(y==0 || y==R-1 || x==0 || x==C-1) return moveTime + 1;
		
		for(int dir=0; dir<4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			
			if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
			if(map[ny][nx] == '#' || visited[ny][nx]) continue;
			if(fireMap[ny][nx] <= moveTime + 1) continue;
			
			visited[ny][nx] = true;
			q.push(make_pair(make_pair(ny, nx), moveTime + 1));
		}
	}
	
	return -1;
}

int main(void) {
	// INPUT
	scanf("%d %d", &R, &C); 
	for(int y=0; y<R; y++) {
		for(int x=0; x<C; x++) {
			bool isFire = false;
			scanf(" %c", &map[y][x]);
			if(map[y][x] == 'J') {
				start.first = y;
				start.second = x;
			}
			else if(map[y][x] == 'F') {
				isFire = true;
				fireMap[y][x] = 0;
				fireTime.push(make_pair(y, x));
			}
			if(!isFire) {
				fireMap[y][x] = 987654321;
			}
		}
	}
	
	// SIMULATION
	spreadFire(); 
	int answer = movePerson();
	
	// OUTPUT
	if(answer == -1) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("%d\n", answer);
	}
	
	return 0;
}
