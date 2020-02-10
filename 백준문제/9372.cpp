#include<iostream>
#include<vector>
using namespace std;

int T, N, M;
vector<int> country[1001];

int main(void) {
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++) {
			int num1, num2;
			scanf("%d %d", num1, num2);
			country[num1].push_back(num2);
			country[num2].push_back(num1);
		}
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=0; j<country[i].size(); j++) {
			printf("%d ", country[i][j]);
		}
		printf("\n");
	}
	return 0;
}
