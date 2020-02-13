#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int N;
vector<int> area[11]; // 1번 ~ N번 구역
int population[11]; // 지역 인구수 저장 
bool check[11]; 
int num = 1;
int answer = 99999;
bool divide = true;

void calcPopulation(vector<int> a, vector<int> b) {
	divide = false;
	int pop_a = 0;
	int pop_b = 0;
	for(int i=0; i<a.size(); i++) {
		pop_a += population[a[i]];
	}
	for(int i=0; i<b.size(); i++) {
		pop_b += population[b[i]];
	}
		
	int gap = abs(pop_a - pop_b);
	if(answer > gap) {
		answer = gap;
	}
}
		
bool isPossible(vector<int> a, vector<int> b) {
	bool visited[11];
	memset(visited, false, sizeof(visited));
	// a 선거구 검사	
	queue<int> q;
	q.push(a[0]);
	visited[a[0]] = true;
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for(int i=0; i<area[cur].size(); i++) {
			int next = area[cur][i];
			if(visited[next]) continue;
			bool flag = true;
			for(int j=0; j<a.size(); j++)  {
				if(next == a[j]) {
					flag = false;
				}
			}
			if(flag) continue;
			
			visited[next] = true;
			q.push(next);
		}
	}
	
	for(int i=0; i<a.size(); i++) {
		if(!visited[a[i]]) return false;
	}
	
	// b 선거구 검사
	memset(visited, false, sizeof(visited));
	while(!q.empty()) {
		q.pop();
	}
	q.push(b[0]);
	visited[b[0]] = true;
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for(int i=0; i<area[cur].size(); i++) {
			int next = area[cur][i];
			if(visited[next]) continue;
			bool flag = true;
			for(int j=0; j<b.size(); j++)  {
				if(next == b[j]) {
					flag = false;
				}
			}
			if(flag) continue;
			
			visited[next] = true;
			q.push(next);
		}
	}
	
	for(int i=0; i<b.size(); i++) {
		if(!visited[b[i]]) return false;
	}
	
	// a, b 둘다 가능 하면 true 반환 
	return true;
}

void dfs(int cnt) {
	if(cnt == num) {
		// a, b 선거구에 지역 번호 등록 
		vector<int> a;
		vector<int> b;
		for(int i=1; i<=N; i++) {
			if(check[i]) {
				a.push_back(i);
			} else {
				b.push_back(i);
			}
		}
		//선거구 가능 검사 (한 곳이라도 불가능시 return) 
		if(!isPossible(a, b)) {		
			return;
		} 
		// 인구 수 차이 구하기 
		calcPopulation(a, b);
		
		return;	
	}
	
	for(int idx=1; idx<=N; idx++) {
		if(check[idx]) continue;
		check[idx] = true;
		dfs(cnt+1);
		check[idx] = false;
	}
}

int main(void) {
	// 입력 
	scanf("%d", &N);
	for(int i=1; i<=N; i++)	 {
		scanf("%d", &population[i]);
	}
	for(int i=1; i<=N; i++) {
		int n;
		scanf("%d", &n);
		for(int j=1; j<=n; j++) {
			int node;
			scanf("%d", &node);
			area[i].push_back(node);
		}
	}
	
	// 선거구 나누기
	for(int cnt=1; cnt<=N/2; cnt++) {
		memset(check, false, sizeof(check));
		dfs(0);
		num++;
	}
	
	// 정답 출력 
	if(divide) {
		printf("-1");
	} else {
		printf("%d\n", answer);	
	}
	
	return 0;
}
