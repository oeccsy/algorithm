#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> s;
    int result = 0;
    char last = NULL;
    
    string input;
    cin >> input;

    for(auto c : input)
    {
        if(c == '(')
        {
            s.push(c);
            last = '(';
        }
        else if(c == ')')
        {
            if(s.top() == '(')
            {
                s.pop();

                if(last == '(')
                {
                    result += s.size(); 
                }
                else if(last == ')')
                {
                    result++;   
                }
            }

            last = ')';
        }
    }

    cout << result;
}