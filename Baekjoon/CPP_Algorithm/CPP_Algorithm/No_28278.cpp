#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> stack;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;

        if(input == 1)
        {
            int x;
            cin >> x;

            stack.push(x);
        }
        else if(input == 2)
        {
            if(stack.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << stack.top() << '\n';
                stack.pop();
            }
        }
        else if (input == 3)
        {
            cout << stack.size() << '\n';
        }
        else if (input == 4)
        {
            if(stack.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (input == 5)
        {
            if(stack.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << stack.top() << '\n';
            }
        }
    }
}