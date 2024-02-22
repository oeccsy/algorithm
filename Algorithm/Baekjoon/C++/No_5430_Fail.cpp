#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> numbers;
bool is_reverse = false;

void Parse(string& s)
{
    bool new_number = true;
    int num = 0;
    for(auto c : s)
    {
        if(0 <= c-'0'&& c-'0' <= 9)
        {
            if(new_number)
            {
                num = 0;
                new_number = false;
            }
            else
            {
                num = numbers.back();
                numbers.pop_back();
            }
            
            num *= 10;
            num += c-'0';
            numbers.push_back(num);
        }
        else if( c == ',')
        {
            new_number = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        is_reverse = false;
        
        string p;
        cin >> p;

        int n;
        cin >> n;

        string input;
        cin >> input;
        Parse(input);

        for(auto oper : p)
        {
            if(oper == 'R')
            {
                is_reverse = !is_reverse;
            }
            else if(oper == 'D')
            {
                if(numbers.empty())
                {
                    break;
                }

                if(is_reverse)
                {
                    numbers.pop_back();
                }
                else
                {
                    numbers.pop_front();
                }
            }
        }

        if(!numbers.empty())
        {
            cout << '[';
            while(!numbers.empty())
            {
                if(is_reverse)
                {
                    cout << numbers.back();
                    numbers.pop_back();
                }
                else
                {
                    cout << numbers.front();
                    numbers.pop_front();
                }

                if(!numbers.empty())
                {
                    cout << ',';
                }
                else
                {
                    break;
                }
            }
            cout << ']' << '\n';
        }
        else
        {
            cout << "error" << '\n';
        }
        
    }
}