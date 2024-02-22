#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = 0;

    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;

        stack<char> word;
        bool is_valid = true;

        for(auto c : input)
        {
            if(word.empty())
            {
                word.push(c);
            }
            else if(word.top() == c)
            {
                word.pop();
            }
            else
            {
                word.push(c);
            }
        }

        if(!word.empty())
        {
            is_valid = false;
        }

        if(is_valid)
        {
            result++;
        }
    }

    cout << result;
}