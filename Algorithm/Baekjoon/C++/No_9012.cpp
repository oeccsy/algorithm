#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        string input;
        cin >> input;

        stack<char> ps;
        bool is_valid = true;
        
        for(auto c : input)
        {
            if(c == '(')
            {
                ps.push(c);   
            }
            else if (c == ')')
            {
                if(ps.empty())
                {
                    is_valid = false;
                    break;
                }
                else if(ps.top() == '(')
                {
                    ps.pop();
                }
                else
                {
                    ps.push(c);
                }
            }
        }

        if(!ps.empty())
        {
            is_valid = false;
        }

        if(is_valid)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}