#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pattern_1[5] = {1, 2, 3, 4, 5};
int pattern_2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int pattern_3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int count_1 = 0;
    int count_2 = 0;
    int count_3 = 0;
    
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == pattern_1[i%5]) count_1++;
        if(answers[i] == pattern_2[i%8]) count_2++;
        if(answers[i] == pattern_3[i%10]) count_3++;
    }
    
    int max_count = max({count_1, count_2, count_3});
    
    if(max_count == count_1) answer.push_back(1);
    if(max_count == count_2) answer.push_back(2);
    if(max_count == count_3) answer.push_back(3);
    
    return answer;
}