#include <string>
#include <vector>
#include <iostream>
#include<cstring>
#include <queue>
using namespace std;

vector<int> getBinaryValue(int n, int num) {
    vector<int> v(n);
    
    int index = n-1;
    while(num != 0) {
        v[index--] = num % 2;
        num /= 2;
    }
    return v;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> v1, v2;
    int map[n][n];
    
    memset(map, 0, sizeof(map));
    for(int i=0; i<n; i++) {
        v1 = getBinaryValue(n, arr1[i]);
        v2 = getBinaryValue(n, arr2[i]);
        
        for(int j=0; j<n; j++) {
            if(v1[j] == 1 || v2[j] == 1) map[i][j] = 1;
        }
    }
    
    for(int y=0; y<n; y++) {
        string str = "";
        for(int x=0; x<n; x++) {
            if(map[y][x] == 1) str += "#";
            else str += " ";
        }
        answer.push_back(str);
    }
    
    return answer;
}
