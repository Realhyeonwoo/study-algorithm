#include<iostream>
#include<vector>
#include<algorithm>

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


// ���� Ŭ���� ����
class Edge {
	public: 
	int node[2];
	int distance;
	Edge(int a, int b, int d) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = d;
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
}; 
int main(void) {
	int n = 7;
	int m = 11;
	
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	// ������ ����� �������� �������� ����
	sort(v.begin(), v.end());
	
	// �� ������ ���Ե� �׷����� ������� ����
	int parent[n+1];
	for(int i=1; i<=n; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for(int i=0; i<v.size(); i++) {
		// ����Ŭ�� �߻����� �ʴ� ��� �׷����� ����
		if(!findParent(parent, v[i].node[0] , v[i].node[1] )) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] , v[i].node[1] );
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}