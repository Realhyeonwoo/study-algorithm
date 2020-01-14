#include<iostream>
#include<stdio.h>
#include <vector>
using namespace std;

vector<int> value;
vector<bool> select;

void Print() {
	for(int i=0; i<value.size(); i++) {
		if(select[i] == true ) {
			printf("%d ", value[i]);
		}
	}
	printf("\n");
}

void DFS(int idx, int cnt, int n, int m) {
	if(cnt == m) {
		Print();
		return;
	}
	
	for(int i=idx; i<n; i++) {
		if(select[i] == true) continue;
		select[i] = true;
		DFS(i, cnt+1, n, m);
		select[i] = false;	
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++) {
		value.push_back(i+1);
		select.push_back(false);
	}
	
	DFS(0, 0, n, m);
	
	return 0; 
}
