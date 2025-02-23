#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s)
{
    vector<string> en_nums;
    en_nums.push_back("zero");
    en_nums.push_back("one");
    en_nums.push_back("two");
    en_nums.push_back("three");
    en_nums.push_back("four");
    en_nums.push_back("five");
    en_nums.push_back("six");
    en_nums.push_back("seven");
    en_nums.push_back("eight");
    en_nums.push_back("nine");
    
    int answer = 0;
    int st = 0;
    int en = 0;
    
    while(st < s.size())
    {
        if('0' <= s[st] && s[st] <= '9')
        {
            en = st + 1;
            answer += s[st] - '0';
            
            if(en < s.size()) answer *= 10;
        }
        else
        {
            for(int i=0; i<=9; i++)
            {
                if(s.substr(st, en_nums[i].size()) == en_nums[i])
                {
                    en = st + en_nums[i].size();
                    answer += i;
                    
                    if(en < s.size()) answer *= 10;
                    break;
                }
            }
        }
        
        st = en;
    }
    
    return answer;
}