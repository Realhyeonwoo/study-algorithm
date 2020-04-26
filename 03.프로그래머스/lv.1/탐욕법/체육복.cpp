#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[n+1];
    for(int i=1; i<=n; i++) student[i] = 1;
    for(int i=0; i<reserve.size(); i++) student[reserve[i]] += 1;
    for(int i=0; i<lost.size(); i++) student[lost[i]] -= 1;
    
    sort(lost.begin(), lost.end());
    
    for(int i=0; i<lost.size(); i++) {
        if(student[lost[i]] != 0) continue;
        
        if(student[lost[i]-1] == 2) {
            student[lost[i]] = 1;
            student[lost[i] - 1] = 1;
        } else if(student[lost[i]+1] == 2){
            student[lost[i]] = 1;
                student[lost[i] + 1] = 1;
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(student[i] != 0) answer++;
    }
    return answer;
}
