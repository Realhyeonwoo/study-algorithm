#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int start = arr[0];
    answer.push_back(start);
    
    for(int i=1; i<arr.size(); i++) {
        if(start != arr[i]) {
            answer.push_back(arr[i]);
            start = arr[i];
        }
    }

    return answer;
}
