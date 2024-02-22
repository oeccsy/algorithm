#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothes_type;
    
    for(int i=0; i<clothes.size(); i++)
    {
        if(clothes_type.count(clothes[i][1]) == 0)
        {
            clothes_type[clothes[i][1]] = 1;
        }
        else
        {
            clothes_type[clothes[i][1]]++;
        }
    }
    
    for(auto data : clothes_type)
    {
        answer *= data.second + 1;
    }
    
    answer--;
    
    return answer;
}