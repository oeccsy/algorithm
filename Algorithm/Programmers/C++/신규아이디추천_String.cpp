#include <string>
#include <vector>
#include <iostream>

using namespace std;

void upper_to_lower(string& id)
{
    for(char& ch : id)
    {
       if(isupper(ch))
       {
           ch = tolower(ch);
       }
    }
}

void remove_invalid_char(string& id)
{
    for(auto it = id.begin(); it != id.end(); )
    {
        char ch = *it;
        
        if(!(('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') || ch == '-' || ch == '_' || ch == '.'))
        {
            it = id.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void compact_dot(string& id)
{
    int count = 0;
    
    for(auto it = id.begin(); it != id.end(); )
    {
        if(*it == '.')
        {
            count++;
            
            if(count >= 2)
            {
                it = id.erase(it);
            }
            else
            {
                it++;
            }
        }
        else
        {
            count = 0;
            it++;
        }
    }
}

void remove_invalid_dot(string& id)
{
    if(id.front() == '.') id.erase(0, 1);
    if(id.back() == '.') id.erase(id.size()-1, 1);
}

void add_char_to_empty(string& id)
{
    if(id.empty()) id += "a";
}

void remove_over_len(string& id)
{
    if(id.length() >= 16) id.erase(15, id.length() - 15);
    if(id.back() == '.') id.erase(id.size()-1, 1);
}

void add_while_min_len(string& id)
{
    while(id.length() <= 2)
    {
        char ch = id.back();
        id += ch;
    }
}

string solution(string new_id)
{
    upper_to_lower(new_id);
    remove_invalid_char(new_id);
    compact_dot(new_id);
    remove_invalid_dot(new_id);
    add_char_to_empty(new_id);
    remove_over_len(new_id);
    add_while_min_len(new_id);
    
    return new_id;
}