#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

class Edge {
	public: 
	int node[2];
	long long distance;
	Edge(int a, int b, long long d) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = d;
	}
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

int T, N;
double E;
int map[1001][2];
vector<Edge> v;

long long d[1001];

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
	scanf("%d", &T);
	for(int test_case=1; test_case<=T; test_case++) {
		// INPUT
		scanf("%d", &N);
		int x, y;
		for(int i=1; i<=N; i++) {
			scanf("%d", &x);
			map[i][0] = x;
		}
		for(int i=1; i<=N; i++) {
			scanf("%d", &y);
			map[i][1] = y;
		}
		scanf("%lf", &E);
		for(int i=1; i<N; i++){
			for(int j=i+1; j<=N; j++) {
				long long distance = floor(((((map[i][0] - map[j][0])*(map[i][0] - map[j][0]))+((map[i][1] - map[j][1])*(map[i][1] - map[j][1]))) * E) + 0.5);
				v.push_back(Edge(i, j, distance));
			}
		}
				
		// SIMULATION
		sort(v.begin(), v.end());
		
		// �� ������ ���Ե� �׷����� ������� ����
		int parent[1001];
		for(int i=1; i<=N; i++) {
			parent[i] = i;
		}
		long long sum = 0;
		for(int i=0; i<v.size(); i++) {
			// ����Ŭ�� �߻����� �ʴ� ��� �׷����� ����
			if(!findParent(parent, v[i].node[0] -1, v[i].node[1] -1)) {
				sum += v[i].distance;
				unionParent(parent, v[i].node[0] -1, v[i].node[1] -1);
			}
		}
	
		printf("%d\n", sum);
	}
	
	return 0;
}
