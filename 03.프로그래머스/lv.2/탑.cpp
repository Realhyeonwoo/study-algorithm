#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for(int i=heights.size()-1; i>=1; i--) {
        bool isFlag = false;
        for(int j=i-1; j>=0; j--) {
            if(heights[j] > heights[i]) {
                answer.push_back(j+1);
                isFlag = true;
                break;
            }
        }
        if(!isFlag) answer.push_back(0);
    }
    
    answer.push_back(0);
    reverse(answer.begin(), answer.end());
    return answer;
}
