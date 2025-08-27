#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<int>> scores;
vector<vector<string>> token_list = { {"cpp", "java", "python"}, {"backend", "frontend"}, {"junior", "senior"}, {"chicken", "pizza"} };

vector<string> split(string& target, string sep)
{
    vector<string> result;
    int st = 0;
    int en = 0;
    
    while((en = target.find(sep, st)) != string::npos)
    {
        string token = target.substr(st, en - st);
        result.push_back(token);
        
        st = en + sep.length();
    }
    
    result.push_back(target.substr(st, target.size() - st));
    
    return result;
}

void register_score(vector<string>& tokens)
{
    string condition;
    for(int i=0; i<tokens.size()-1; i++) condition += tokens[i];
    
    int score = stoi(tokens.back());
    
    scores[condition].push_back(score);
}

int count(vector<string>& tokens, int cur_depth, string condition)
{   
    int total_count = 0;
    string cur_token = tokens[cur_depth];
    
    if(cur_depth == tokens.size() - 1)
    {
        int score = stoi(cur_token);
        vector<int>& score_vec = scores[condition];
        
        return score_vec.end() - lower_bound(score_vec.begin(), score_vec.end(), score);
    }
    
    if(cur_token == "and")
    {
        total_count = count(tokens, cur_depth + 1, condition);
    }
    else if(cur_token == "-")
    {
        for(string token : token_list[cur_depth / 2])
            total_count += count(tokens, cur_depth + 1, condition + token);
    }
    else
    {
        total_count = count(tokens, cur_depth + 1, condition + cur_token);
    }
    
    return total_count;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    for(string cur_info : info)
    {
        vector<string> tokens = split(cur_info, " ");
        register_score(tokens);
    }
    
    for(auto& pair : scores)
    {
        sort(pair.second.begin(), pair.second.end());
    }
    
    vector<int> answer;
    
    for(string cur_query : query)
    {
        vector<string> tokens = split(cur_query, " ");
        answer.push_back(count(tokens, 0, ""));
    }
    
    return answer;
}