#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

int N;
vector<pair<int, int> > node;
bool visited[12];
vector<int> temp;
int sum;
int answer = 987654321;
void line_dfs(int start, int cnt) {
	if(cnt == N-2) {
		temp.push_back(N-1);
		sum = 0;
		int start_x = node[0].first;
		int start_y = node[0].second;
		
		// 회사 0
		// 방문 1 ~ N-2 
		// 집 N-1 
		int distance;
		for(int i=0; i<temp.size(); i++) {
			distance = abs(start_x - node[temp[i]].first) + abs(start_y - node[temp[i]].second);
			sum += distance;
			if(answer < sum) break;
			start_x = node[temp[i]].first;
			start_y = node[temp[i]].second;
		}
		answer = sum;
		
		return;
	}
	for(int i = 1; i<N-1; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		temp.push_back(i);
		line_dfs(start, cnt+1);
		visited[i] = false;
		temp.pop_back();
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		// INPUT
		scanf("%d", &N);
		int x, y;
		int home_x, home_y;
		for(int i=0; i<N; i++) {
			scanf("%d %d", &x, &y);
			if(i==1) {
				home_x = x; home_y = y;
				continue;
			}
			node.push_back(make_pair(x, y));
		}
		node.push_back(make_pair(home_x, home_y));
		
		// SIMULATION
		line_dfs(0, 0);
		
		
		printf("#%d %d\n", test_case, answer);


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
