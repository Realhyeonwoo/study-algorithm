#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2) {
    return p1.first == p2.first ? p1.second < p2.second : p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail;
    double sum = 0;
    double size = (double)stages.size();
    
    for(int s=1; s<=N; s++) {
        sum = 0;
        for(int i=0; i<stages.size(); i++) {
            if(s == stages[i]) sum++;
        }
        if(sum == 0)  {
        		fail.push_back(make_pair(0.0, s));
		  } else {
	        fail.push_back(make_pair(sum/size, s));
	        size -= sum;
		  }
    }
    sort(fail.begin(), fail.end(), compare);
    for(int i=0; i<fail.size(); i++) answer.push_back(fail[i].second);
    
    return answer;
}
