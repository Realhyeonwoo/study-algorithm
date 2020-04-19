#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define MAX 11
using namespace std;

int map[MAX][MAX];
vector<pair<int, int> > v;

bool isTriangle() {
	int a = abs(v[0].first - v[1].first) * abs(v[0].first - v[1].first) + abs(v[0].second - v[1].second) * abs(v[0].second - v[1].second);
	int b = abs(v[0].first - v[2].first) * abs(v[0].first - v[2].first) + abs(v[0].second - v[2].second) * abs(v[0].second - v[2].second);
	int c = abs(v[2].first - v[1].first) * abs(v[2].first - v[1].first) + abs(v[2].second - v[1].second) * abs(v[2].second - v[1].second);
	
	
	if((a == b+c) || (c == b+a) || (b == a+c)) {
		if(a==b || b==c || c==a) return true;
		else return false;		
	} else {
		return false;
	}
}

int main(void) {
	// �Է¹����鼭 �ﰢ�� ���� ���� 1�� ä�����ִ��� �� �� (������ �������鼭) 
	bool isEmpty = false;
	for(int y=1; y<MAX; y++) {
		vector<int> temp;
		for(int x=1; x<MAX; x++) {
			scanf("%1d", &map[y][x]);
			if(map[y][x] == 1) temp.push_back(x);
		}
		
		if(!isEmpty && temp.size() != 0) {
			for(int i=0; i<temp.size()-1; i++) {
				if(temp[i]+1 != temp[i+1]) {
					isEmpty = true;
					break;
				}
			}		
		}
		temp.clear();
	}
	
	if(isEmpty) {
		printf("0");
		return 0;
	}
	
	// �ﰢ�� ���� 1�� �� ä�����ִ��� �˻�(���� �������鼭) 
	for(int x=1; x<MAX; x++) {
		vector<int> temp;
		for(int y=1; y<MAX; y++) {
			if(map[y][x] == 1) temp.push_back(y);
		}
		
		if(!isEmpty && temp.size() != 0) {
			for(int i=0; i<temp.size()-1; i++) {
				if(temp[i]+1 != temp[i+1]) {
					isEmpty = true;
					break;
				}
			}		
		}
		temp.clear();
	}
	
	if(isEmpty) {
		printf("0\n");
		return 0;
	}
	
	// �ﰢ���� �� ������ ���ϱ�(vector v�� ������ ����) 
	for(int y=1; y<MAX; y++) {
		int count = 0, temp = 0;
		for(int x=1; x<MAX; x++) {
			if(map[y][x] == 1) count++;
		}
		if(count == 1) {
			for(int x=1; x<MAX; x++) {
				if(map[y][x] == 1) {
					v.push_back(make_pair(y, x));
				}
			}
		}
	}
	for(int x=1; x<MAX; x++) {
		int count = 0;
		for(int y=1; y<MAX; y++) {
			if(map[y][x] == 1) count++;
		}
		if(count == 1) {
			for(int y=1; y<MAX; y++) {
				if(map[y][x] == 1) {
					v.push_back(make_pair(y, x));
				}
			}
		}
	}
	
	// ������ ���� 
	sort(v.begin(), v.end());
	
	// �����ﰢ�� ���� �����ϴ��� �˻�: �������� 3���̸� �� ���̻� ���ƾ��ϸ� ��Ÿ��� ������ ���� 
	if(v.size() == 3 && isTriangle()) {
		for(int i=0; i<v.size(); i++) {
			printf("%d %d\n", v[i].first, v[i].second);
		}
	} else {
		printf("0\n");
	}
	
	return 0;
}
