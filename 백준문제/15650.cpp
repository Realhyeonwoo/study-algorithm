#include<iostream>
#include<cstdio>
#include<stdio.h>
#include <vector>
using namespace std;

vector<int> value;
vector<bool> visit;
int n, m;

void Print() {
	for(int i=0; i<value.size(); i++) {
		if(visit[i] == true ) {
			printf("%d ", value[i]);
		}
	}
	printf("\n");
}

void DFS(int idx, int cnt) {
	if(cnt == m) {
		Print();
		return;
	}
	
	for(int i=idx; i<n; i++) {
		if(visit[i]) continue;
		visit[i] = true;
		DFS(i, cnt+1);
		visit[i] = false;	
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++) {
		value.push_back(i+1);
		visit.push_back(false);
	}

	DFS(0, 0);
	
	return 0; 
}
