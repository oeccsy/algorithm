#include <iostream>
#include <stack>

using namespace std;



int main()
{
    int k;
    int input;
    stack<int> stack;

    long long total = 0;
    
    cin >> k;

    for(int i=0; i<k; i++)
    {
        cin >> input;

        if(input == 0)
        {
            stack.pop();
        }
        else
        {
            stack.push(input);
        }
    }

    while(true)
    {
        if(stack.empty()) break;
        
        total += stack.top();
        stack.pop();
    }

    cout << total;
}
