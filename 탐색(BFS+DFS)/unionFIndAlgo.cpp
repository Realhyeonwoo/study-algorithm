#include<iostream>
using namespace std;

// �θ� ��鸣 ã�� �Լ� 
int getParent(int parent[], int x) {
	if(x == parent[x]) return x;
	
	return getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) {
		parent[b] = a;
	} else {
		parent[a] = b;
	}
}

// ���� �θ� �������� Ȯ�� (cycle ���� Ȯ��)
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
