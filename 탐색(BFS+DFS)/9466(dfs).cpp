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



//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//int T, n;
//int node[100001];
//bool visited[100001];
//bool isChecked[100010];
//int answer;
//
//void dfs(int start, int current) {
//	if(start == current) {
//		for(int i=1; i<=n; i++) {
//			if(visited[i]) {
//				answer++; 
//				node[i] = 0;
//			}
//		}
//		return;
//	}
//	
//	if(isChecked[current]) return;
//	if(node[current] == 0 || visited[current]) return;
//	
//	visited[current] = true;
//	isChecked[current] = true;
//	dfs(start, node[current]);
//}
//
//int main(void) {
//	scanf("%d", &T);
//	for(int test_case=1; test_case<=T; test_case++) {
//		// RESET
//		answer = 0; 
//		memset(node, 0, sizeof(node));
//		memset(isChecked, false, sizeof(isChecked));
//		
//		// INPUT
//		scanf("%d", &n);
//		for(int i=1; i<=n; i++)	{
//			scanf("%d", &node[i]);
//			if(node[i] == i) {
//				node[i] = 0;
//				answer++; 		
//			}
//		}
//		
//		// SIMULATION
//		for(int i=1; i<=n; i++) {
//			if(node[i] == 0 || isChecked[i]) continue;
//			
//			memset(visited, false, sizeof(visited));
//			visited[i] = true;
//			isChecked[i] = true;
//			dfs(i, node[i]);
//		}
//	
//		// OUTPUT
//		printf("%d\n", n - answer);
//	
//	}
//	return 0;
//}
