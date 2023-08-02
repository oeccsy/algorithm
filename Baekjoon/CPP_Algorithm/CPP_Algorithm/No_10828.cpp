#include <iostream>

using namespace std;

int stack[10001] = {0, };
int pos = 0;

void push(int x)
{
    stack[pos] = x;
    pos++;
}

void pop()
{
    if(pos == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        pos--;
        cout << stack[pos] << '\n';
    }
}

void size()
{
    cout << pos << '\n';
}

void empty()
{
    if(pos == 0)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

void top()
{
    if(pos == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << stack[pos-1] << '\n';    
    }
}

int main()
{
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        string input;
        int num;
        cin >> input;

        if(input == "push")
        {
            cin >> num;
            push(num);
        }
        if(input == "pop")
        {
            pop();
        }
        if(input == "size")
        {
            size();
        }
        if(input == "empty")
        {
            empty();
        }
        if(input == "top")
        {
            top();
        }
    }
}
