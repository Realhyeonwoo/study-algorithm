#include<iostream> 
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int arr[1001];
vector<int> answer;

// BFS
//void Solve(int start, int n) {
//	bool visited[1001];
//	memset(visited, false, sizeof(visited));
//	
//	queue<int> q;
//	q.push(arr[start]);
//	visited[start] = true;
//	
//	int count = 0; 
//	while(!q.empty()) {
//		int x = q.front();
//		q.pop();
//		
//		if(!visited[x]){
//			q.push(arr[x]);
//			visited[x] = true;
//		} else {
//			count += 1;
//			for(int i=1; i<=n; i++) {
//				if(!visited[i]) {
//					q.push(arr[i]);
//					break;
//				}
//			}
//		}
//	}
//	answer.push_back(count);
//}
//
//int main(void) {
//	int T; 
//	scanf("%d", &T);
//	for(int i=0; i<T; i++){
//		int n;
//		scanf("%d", &n); 
//		for(int i=1; i<=n; i++) {
//			scanf("%d", &arr[i]);
//		}
//		Solve(1, n);
//		memset(arr, 0, sizeof(arr));
//	}
//	
//	for(int i=0; i<answer.size(); i++) {
//		printf("%d\n", answer[i]);
//	}
//	return 0; 
//}


// DFS
bool visited[1001] = {false, };

void Dfs(int start){
	int next = arr[start];
	if(!visited[next]) {
		visited[next] = true;
		Dfs(next);
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(visited, false, sizeof(visited));
		int num;
		scanf("%d", &num);
		
		for(int i=1; i<=num; i++) {
			scanf("%d", &arr[i]);
		}
		
		int result = 0; 
		for(int i=1; i<=num; i++) {
			if(!visited[i]) {
				Dfs(i);
				result++;
			}
		}
		printf("%d\n", result);
	}
}
