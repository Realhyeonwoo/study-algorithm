#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    
    for(int i=0; i<progresses.size(); i++) {
        int start = 0;
        while(1) {
            start++;
            if(progresses[i] + speeds[i] >= 100) break;
            progresses[i] += speeds[i];
        }
        day.push_back(start);
    }
    
    for(int i=0; i<day.size(); i++) printf("%d ", day[i]);
    printf("\n");
    stack<int> stk;
    int Max = -1;
    for(int i=0; i<day.size(); i++) {
        
        if(!stk.empty() && Max < day[i]) {
            answer.push_back(stk.size());
            while(!stk.empty()) stk.pop();
            Max = -1;
        }
        stk.push(i);
        Max = max(Max, day[i]);
    }
    answer.push_back(stk.size());
    return answer;
}
