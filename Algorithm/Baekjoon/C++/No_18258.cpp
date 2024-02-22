#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 2000001;
int q[MAX_SIZE] = {0, };

int head = 0;
int tail = 0;
 
void Push(int x)
{
    q[tail] = x;
    tail++;

    if(tail == MAX_SIZE) tail = 0;
}

void Pop()
{
    if(head == tail)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << q[head] << '\n';
        head ++;

        if(head == MAX_SIZE) head = 0;
    }
}

void Size()
{
    if(tail - head >= 0)
    {
        cout << tail - head << '\n';
    }
    else
    {
        cout << tail + MAX_SIZE - head << '\n';
    }
}

void Empty()
{
    if(head == tail)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

void Front()
{
    if(head == tail)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << q[head] << '\n';
    }
}

void Back()
{
    if(head == tail)
    {
        cout << -1 << '\n';
    }
    else
    {
        if(tail == 0)
        {
            cout << q[MAX_SIZE] << '\n';
        }
        else
        {
            cout << q[tail-1] << '\n';   
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;

        if(input == "push")
        {
            int x;
            cin >> x;
            Push(x);
        }
        else if(input == "pop")
        {
            Pop();
        }
        else if(input == "size")
        {
            Size();
        }
        else if(input == "empty")
        {
            Empty();
        }
        else if(input == "front")
        {
            Front();
        }
        else if(input == "back")
        {
            Back();
        }
    }
}
