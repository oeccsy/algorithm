#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> comp_count;
    
    for(auto c : completion)
    {
        int c_count = comp_count[c];
        comp_count[c] = c_count + 1;
    }
    
    for(auto p : participant)
    {   
        int c_count = comp_count[p];
        c_count--;
        
        if(c_count < 0)
        {
            answer = p;
            break;
        }
        
        comp_count[p] = c_count;
    }
    
    return answer;
}