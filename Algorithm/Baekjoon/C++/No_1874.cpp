#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<int> numbers;
    stack<int> storage;
    vector<char> oper;
    
    int n;
    cin >> n;

    for(int i=n; i>=1; i--)
    {
        numbers.push(i);
    }

    for(int i=0; i<n; i++)
    {
        int target;
        cin >> target;

        while(true)
        {
            if(!storage.empty() && storage.top() == target)
            {
                storage.pop();
                oper.push_back('-');
                break;
            }
            else if(!numbers.empty() && numbers.top() <= target)
            {
                int num = numbers.top();
                numbers.pop();
                storage.push(num);
                oper.push_back('+');
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }

    for(auto o : oper)
    {
        cout << o << '\n';
    }
}
