#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one[] = {1, 2, 3, 4, 5};
    int two[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int answer1 = 0, answer2 = 0, answer3 = 0;
    for(int i=0; i<answers.size(); i++) {
        if(one[i%5] == answers[i]) answer1++;
        if(two[i%8] == answers[i]) answer2++;
        if(three[i%10] == answers[i]) answer3++;
    }
    
    vector<pair<int, int>> res;
    res.push_back(make_pair(answer1, 1));
    res.push_back(make_pair(answer2, 2));
    res.push_back(make_pair(answer3, 3));
    sort(res.begin(), res.end());
    
    int maxValeu = res[2].first;
    
    for(int i=0; i<res.size(); i++) {
        if(res[2].first == res[i].first) answer.push_back(res[i].second);
    }
    
    return answer;
}
