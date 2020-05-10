#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> stk;
    
    for(int i=0; i<arrangement.size(); i++) {
        if(arrangement[i] == '(') stk.push(arrangement[i]);
        else {
            stk.pop();
            if(arrangement[i-1] == '(') answer += stk.size();
            else answer++;
        }
    }
    return answer;
}
