//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//
//int N;
//int node[101]; // 1 ~ 100
//int visited[101];
//vector<int> answer;
//
//void dfs(int start, int current) {
//	if(start == current) {
//		for(int i=1; i<=N; i++) {
//			if(visited[i]) {
//				answer.push_back(i);
//				node[i] = 0;
//			}
//		}
//		return;
//	}
//	if(visited[current]) return;
//	if(node[current] == 0) return;
//	
//	visited[current] = 1;	
//	
//	dfs(start, node[current]);
//}
//
//int main(void) {
//	// INPUT
//	scanf("%d", &N);
//	for(int i=1; i<=N; i++) {	
//		scanf("%d", &node[i]);
//		if(i == node[i]) {
//			answer.push_back(i);
//			node[i] = 0;
//		}
//	}
//	// SIMULATION
//	for(int i=1; i<=N; i++) {
//		if(node[i] == 0) continue;
//		
//		memset(visited, false, sizeof(visited));
//		visited[i] = 1;
//		dfs(i, node[i]);
//	}
//	// OUTPUT
//	printf("%d\n", answer.size());
//	sort(answer.begin(), answer.end());
//	for(int i=0; i<answer.size(); i++) {
//		printf("%d\n", answer[i]);
//	}
//}



//#include<iostream>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//int N;
//int node[101];
//int visited[101];
//int startNode[101];
//vector<int> answer;
//
//void dfs(int start, int current) {
//	if(start == current) {
//		for(int i=1; i<=N; i++) {
//			if(visited[i]) {
//				answer.push_back(i);
//			}
//		}
//		return;
//	}
//	
//	if(visited[current]) return;
//	
//	startNode[current] = start;
//	visited[current] = true;
//	
//	dfs(start, node[current]);
//}
//
//int main(void) {
//	// INPUT
//	scanf("%d", &N);
//	for(int i=1; i<=N; i++) {
//		scanf("%d", &node[i]);
//	}
//	// SIMULATION
//	for(int i=1; i<=N; i++) {
//		if(node[i] == i) {
//			startNode[i] = i;
//			answer.push_back(i);
//		}
//		if(startNode[i] != 0) continue;
//		
//		memset(visited, false, sizeof(visited));
//		visited[i] = true;
//		dfs(i, node[i]);
//	}
//	// OUTPUT
//	sort(answer.begin(), answer.end());
//	printf("%d\n", answer.size());
//	for(int i=0; i<answer.size(); i++) {
//		printf("%d\n", answer[i]);
//	}
//}




#include<iostream>
#include<cstring>
using namespace std;

int n;
int node[100001];
int startNode[100001];
int visited[100001];
int answer;

int check_dfs(int start, int current, int count) {
	if(visited[current]) {
		return start != startNode[current] ? 0 : count - visited[current];
	}
	
	startNode[current] = start;
	visited[current] = count;
	return check_dfs(start, node[current], count+1);
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// RESET
		memset(node, 0, sizeof(node));
		memset(startNode, 0, sizeof(startNode));
		memset(visited, 0, sizeof(visited));
		answer = 0; 
		// INPUT
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &node[i]);
		}
		// SIMULATION
		for(int i=1; i<=n; i++) {
			if(visited[i] == 0) {
				answer += check_dfs(i, i, 1);
			}
		}
		// OUTPUT
		printf("%d\n", n - answer);
	}
	return 0;
}
