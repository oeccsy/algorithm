#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id)
{
    string answer = new_id;
    
    // step 1
    for(char& ch : answer) if(isupper(ch)) ch = tolower(ch);
    
    // step 2
    string temp;
    for(char& ch : answer)
        if(('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') || string("-_.").find(ch) != string::npos)
            temp += ch;
    
    answer = temp;
    temp.clear();
    
    // step 3
    char prev = 0;
    for(char& ch : answer)
    {
        if(prev == '.' && ch == '.') continue;
        temp += ch;
        prev = ch;
    }
    answer = temp;
    temp.clear();
    
    // step 4
    if(answer.front() == '.') answer.erase(answer.begin());
    if(answer.back() == '.') answer.pop_back();
    
    // step 5
    if(answer.empty()) answer = "a";
    
    // step 6
    if(answer.length() >= 16) answer = answer.substr(0, 15);
    if(answer.back() == '.') answer.pop_back();
    
    // step 7
    while(answer.length() <= 2) answer += answer.back();
    
    return answer;
}