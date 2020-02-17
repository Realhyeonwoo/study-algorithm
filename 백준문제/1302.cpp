#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool compareBook(const pair<string, int> &a, const pair<string, int> &b) {
	return a.second > b.second;
}

bool compareName(const pair<string, int> &a, const pair<string, int> &b) {
	return a.first < b.first;
}

int main(void) {
	int N;
	vector<pair<string, int> > list;
	
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		string str;
		cin >> str;
		
		bool check = true;
		for(int i=0; i<list.size(); i++) {
			if(str == list[i].first) {
				list[i].second++;
				check = false;
				break;
			}
		}
		if(check) {
			list.push_back(make_pair(str, 1));
		}
	}
	
	sort(list.begin(), list.end(), compareBook);
	
	vector<pair<string, int> > answer;
	int maxV = list[0].second;
	for(int i=0; i<list.size(); i++) {
		if(list[i].second == maxV) {
			answer.push_back(make_pair(list[i].first, list[i].second));
		}
	}
	
	if(answer.size() == 1) {
		cout << answer[0].first << endl;
	} else {
		sort(answer.begin(), answer.end(), compareName);
		cout << answer[0].first << endl;
	}
	
	
	return 0; 
}
