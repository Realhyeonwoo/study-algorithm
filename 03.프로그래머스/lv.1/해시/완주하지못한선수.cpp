#include <string>
#include <vector>
#include<map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    // Map에 참가자 상태 저장 
    for(int i=0; i<participant.size(); i++) {
        if(m.count(participant[i]) == 0) {
            m.insert(make_pair(participant[i], 1));
        } else {
            m[participant[i]] += 1;
        }
    }
    
    // completion과 비교
    for(int i=0; i<completion.size(); i++) {
        m[completion[i]] -= 1;
    }
    
    // map에 남아있는 선수 검사
    map<string, int>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++) {
        if(iter->second != 0) {
            answer = iter->first;
            break;
        }
    }
    return answer;
}
