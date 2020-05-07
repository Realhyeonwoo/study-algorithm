#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, count = 0, index = 0;
    
    for(int i=0; i<skill_trees.size(); i++) {
        count = 0;
        for(int j=0; j<skill_trees[i].length(); j++){
            for(int k=0; k<skill.length(); k++) {
                if(skill[k] == skill_trees[i][j]) count++;
            }
        }
        index = 0;
        for(int j=0; j<skill_trees[i].length(); j++){
            if(skill[index] == skill_trees[i][j]) index++;
        }
        if(count == index) answer++;
    }
    return answer;
}
