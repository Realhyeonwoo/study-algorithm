#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool visited[300001];
vector<int> idx;

void dfs(int start, int cnt, int n, vector<int> v, string road) {
	for(int i=0; i<v.size(); i++) {
		if(road[v[i]] == '0')
	}
	if(cnt == n) {
		for(int i=0; i<idx.size(); i++) {
			printf("%d ", v[idx[i]]);
		}
		printf("\n");
		return;
	}
	
	for(int i=start; i<v.size(); i++) {
		if(visited[i]) continue;
		visited[i] = true;
		idx.push_back(i);
		dfs(i, cnt + 1, n, v, road);
		visited[i] = false;
		idx.pop_back();
	}
}
int solution(string road, int n) {
	vector<int> v;
	
	// 0�ΰ� �ε��� ���� 
	for(int i=0; i<road.length(); i++) {
		if(road[i] == '0') v.push_back(i);
	}
	
	// 0�ΰ� ���������ؼ� 1�� ��ȯ
	dfs(0, 0, n, v, road);
	// ���� �ִ� 1���� ���
	
	// ��ȯ 
}
int main(void) {
	int answer = solution("111011110011111011111100011111", 3);
	printf("#1 %d\n", answer);
	memset(visited, false, sizeof(visited));
	idx.clear();
//	answer = solution("001100", 5);
//	printf("#2 %d\n", answer);
	return 0;
}
