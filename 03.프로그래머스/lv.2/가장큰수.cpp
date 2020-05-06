#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string a, const string b) {
    return a + b > b + a ? true : false;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strArr;
    for(int i=0; i<numbers.size(); i++) {
        strArr.push_back(to_string(numbers.at(i)));
    }
    sort(strArr.begin(), strArr.end(), compare);
    
    for(int i=0; i<strArr.size(); i++) answer += strArr[i];
    if(answer[0] == '0') answer = "0";
    return answer;
}
