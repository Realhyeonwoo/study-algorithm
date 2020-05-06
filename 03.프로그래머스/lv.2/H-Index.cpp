#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i=0 ;i<=*max_element(citations.begin(), citations.end()); i++) {
        int count = 0;
        for(int j=0; j<citations.size(); j++) {
            if(i <= citations[j]) count++;
        }
        if(i <= count) answer = max(answer, i);
    }
    
    return answer;
}
