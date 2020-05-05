#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    int multi = 1;
    while(true) {
        bool isFlag = false;
        int standard = arr[arr.size() - 1] * multi;
        for(int i=0; i<arr.size()-1; i++) {
            if(standard % arr[i] != 0) {
                isFlag = true;
                break;
            }
        }
        if(!isFlag) {
            answer = standard;
            break;
        }
        multi++;
    }
    return answer;
}
