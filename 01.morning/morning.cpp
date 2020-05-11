#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> arr;
    stringstream ss(s);
    string token;
    while(getline(ss, token, ' ')) {
		arr.push_back(stoi(token));
    }
    sort(arr.begin(), arr.end());
    answer = to_string(arr[0]) + " " + to_string(arr[arr.size() - 1]);
    return answer;
}

int main(void) {
	string str = "1 -2 -3 -4";
	cout << solution(str) << endl;
	return 0;
}
