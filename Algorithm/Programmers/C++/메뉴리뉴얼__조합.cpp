#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> course_counts;

void count_valid_comb(string& order, int& len, string& temp_comb, int index)
{
    if(temp_comb.length() == len)
    {
        course_counts[temp_comb]++;
        return;
    }
    
    for(int i=index; i<order.size(); i++)
    {
        temp_comb += order[i];
        count_valid_comb(order, len, temp_comb, i + 1);
        temp_comb.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    
    for(int len : course)
    {
        for(string order : orders)
        {
            string temp_comb = "";
            sort(order.begin(), order.end());
            count_valid_comb(order, len, temp_comb, 0);
        }
        
        int max_count = 0;
        for(auto pair : course_counts) max_count = max(max_count, pair.second);
        
        if(max_count >= 2) for(auto pair : course_counts) if(pair.second == max_count) answer.push_back(pair.first);
        
        course_counts.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}