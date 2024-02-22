#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true)
    {
        string input;
        stack<char> parenthesis;
        bool valid = true;
        
        getline(cin, input);
        if(input == ".") break;

        for (int i = 0; i < input.size(); i++)
        {
            if(input[i] == '(')
            {
                parenthesis.push(input[i]);
            }
            else if(input[i] == ')')
            {
                if(parenthesis.empty() || parenthesis.top() != '(')
                {
                    valid = false;
                    break;
                }
                else if(parenthesis.top() == '(')
                {
                    parenthesis.pop();
                }
            }
            else if(input[i] == '[')
            {
                parenthesis.push(input[i]);
            }
            else if(input[i] == ']')
            {
                if(parenthesis.empty() || parenthesis.top() != '[')
                {
                    valid = false;
                    break;
                }
                else if(parenthesis.top() == '[')
                {
                    parenthesis.pop();
                }
            }
        }

        if(!parenthesis.empty())
        {
            valid = false;
        }
        
        if(valid)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
}
