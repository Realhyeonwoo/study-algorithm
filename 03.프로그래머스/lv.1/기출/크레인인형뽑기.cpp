#include<iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> board[], vector<int> moves) {
    int answer = 0;
    vector<int> bucket; 

    for(int m=0; m<moves.size(); m++) {
        int line = moves[m] - 1;
        bool isCatch = false;

        for(int r=0; r<5; r++) {
            if(board[r][line] != 0) {
                bucket.push_back(board[r][line]);
                board[r][line] = 0;
                isCatch = true;
                break;
            }
        }

        if(isCatch && bucket.size() != 0) {
            int size = bucket.size();
            if(bucket[size-1] == bucket[size-2]) {
                answer += 2;
                bucket.erase(bucket.begin()+(size-2), bucket.begin()+size);
            }
        }
    }
    return answer;
}

int main(void) {
	vector<int> v[5];
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(0);
	v[0].push_back(0);
	v[1].push_back(0);
	v[1].push_back(0);
	v[1].push_back(1);
	v[1].push_back(0);
	v[1].push_back(3);
	v[2].push_back(0);
	v[2].push_back(2);
	v[2].push_back(5);
	v[2].push_back(0);
	v[2].push_back(1);
	v[3].push_back(4);
	v[3].push_back(2);
	v[3].push_back(4);
	v[3].push_back(4);
	v[3].push_back(2);	
	v[4].push_back(3);
	v[4].push_back(5);
	v[4].push_back(1);
	v[4].push_back(3);
	v[4].push_back(1);
	
	vector<int> a;
	a.push_back(1);
	a.push_back(5);
	a.push_back(3);
	a.push_back(5);
	a.push_back(1);
	a.push_back(2);
	a.push_back(1);
	a.push_back(4);
	
	int ans = solution(v, a);
	printf("%d\n", ans);
	return 0;
}
