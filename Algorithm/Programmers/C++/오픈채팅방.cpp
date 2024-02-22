#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user_nickname_map;
    
    for(auto message : record)
    {
        stringstream ss(message);
        string cmd;
        
        ss >> cmd;
        
        if(cmd == "Enter" || cmd == "Change")
        {
            string user_id;
            string nickname;
            
            ss >> user_id;
            ss >> nickname;
            
            user_nickname_map[user_id] = nickname;
        }
    }
    
    for(auto message : record)
    {
        stringstream ss(message);
        string cmd;
        
        ss >> cmd;
        
        if(cmd == "Enter")
        {
            string user_id;
            string nickname;
            
            ss >> user_id;
            ss >> nickname;
            
            nickname = user_nickname_map[user_id];
            
            answer.push_back(nickname+"님이 들어왔습니다.");
        }
        else if(cmd == "Leave")
        {
            string user_id;
            string nickname;
            
            ss >> user_id;
            
            nickname = user_nickname_map[user_id];
            
            answer.push_back(nickname+"님이 나갔습니다.");
        }
    }
    
    return answer;
}