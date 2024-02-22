#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;


bool solution(vector<string> phone_book) {
    
    unordered_set<string> uset(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size(); i++)
    {
        string target = "";
        for(int j=0; j<phone_book[i].size(); j++)
        {
            target += phone_book[i][j];
            if(uset.count(target) && target != phone_book[i])
            {
                return false;
            }
        }
    }
    
    return true;
}