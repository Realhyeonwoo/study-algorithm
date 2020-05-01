#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3];
    for(int i=0; i<3; i++) score[i] = 0;
    int index = 0;
    
    for(int i=0; i<dartResult.length(); i++) {
        if(dartResult[i] == 'S') {
            continue;
        } else if(dartResult[i] == 'D'){
            score[index-1] = score[index-1] * score[index-1];
        } else if(dartResult[i] == 'T'){
            score[index-1] = score[index-1] * score[index-1] * score[index-1];
        } else if(dartResult[i] == '#'){
            score[index-1] *= -1;
        } else if(dartResult[i] == '*'){
            score[index-1] *= 2;
            if(index > 1) {
                score[index-2] *= 2;
            }
        } else {
            if(dartResult[i+1] == '0'){
                score[index] = 10;
                i+=1;
            } else {
                score[index] = dartResult[i] - '0';
            }
            index++;
        }
    }
    
    for(int i=0; i<3; i++) {
        answer += score[i];
    }
    
    return answer;
}
