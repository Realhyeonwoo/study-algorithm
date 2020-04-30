#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> dq;
    
    for(int i=0; i<priorities.size(); i++) {
        dq.push_back(make_pair(priorities[i], i));
    }
    int maxValue = *max_element(priorities.begin(), priorities.end());
    
    while(1) {
        if(dq.front().first < maxValue) {
            printf("뒤로: %d %d\n", dq.front().first, dq.front().second);
            dq.push_back(dq.front());
            dq.pop_front();
        } else {
            printf("출력: %d %d\n", dq.front().first, dq.front().second);
            answer++;
            for(int i=0; i<priorities.size(); i++) {
                if(dq.front().first == priorities[i]){
                     priorities[i] = -1;
                    break;
                }
            }
            maxValue = *max_element(priorities.begin(), priorities.end());
            if(dq.front().second == location) {
                printf("break: %d %d\n", dq.front().first, dq.front().second);
                break;
            }
            
            dq.pop_front();
        }
    }
    
    return answer;
}
