#include<iostream>
using namespace std;

// 부모 노들르 찾는 함수 
int getParent(int parent[], int x) {
	if(x == parent[x]) return x;
	
	return getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}

// 같은 부모를 가지는지 확인 (cycle 생성 확인)
bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	return a == b ? true : false;
}

int main(void) {
	int parent[11];
	for(int i=1; i<11; i++) {
		parent[i] = i;
	}
	
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	
	printf("1, 5 => %s\n", findParent(parent, 1, 5) ? "true" : "false");
	printf("1, 3 => %s\n", findParent(parent, 1, 3) ? "true" : "false");
	unionParent(parent, 1, 7);
	printf("1, 5 => %s\n", findParent(parent, 1, 5) ? "true" : "false");
}
