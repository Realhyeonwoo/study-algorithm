#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

int N;
vector<int> area[11]; // 1�� ~ N�� ����
int population[11]; // ���� �α��� ���� 
bool check[11]; 
int num = 1;
int answer = 99999;
bool divide = true;

void calcPopulation(vector<int> a, vector<int> b) {
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

	
	return true;
}

void dfs(int cnt) {
	if(cnt == num) {
		// a, b ���ű��� ���� ��ȣ ��� 
		vector<int> a;
		vector<int> b;
		for(int i=1; i<=N; i++) {
			if(check[i]) {
				printf("%d ", i);
				a.push_back(i);
			} else {
				b.push_back(i);
			}
		}
//		printf("\n");
		//���ű� ���� �˻� (�Ұ����ϸ� return) 
		if(isPossible(a, b)) {
			printf("����\n");
			divide = false; 			
			// �α� �� ���� ���ϱ� 
			calcPopulation(a, b);
			 
		} else {
			printf("�Ұ���\n");	
		}
		
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
	// �Է� 
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
	
	// ���ű� ������
	for(int cnt=1; cnt<=N/2; cnt++) {
		memset(check, false, sizeof(check));
		printf("=======%d��=======\n", cnt);
		dfs(0);
		num++;
	}
	
	// ���� ��� 
	if(divide) {
		printf("-1");
	} else {
		printf("%d\n", answer);	
	}
	
	return 0;
}
