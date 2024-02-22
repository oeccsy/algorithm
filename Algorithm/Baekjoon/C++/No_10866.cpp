#include <iostream>

using namespace std;

const int MAX_SIZE = 20002;
int d[MAX_SIZE] = {0, }; 
int head = 10001;
int tail = 10001;

void PushFront(int x)
{
    head--;
    d[head] = x;
}

void PushBack(int x)
{
    d[tail] = x;
    tail++;
}

void PopFront()
{
    if(head == tail)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << d[head] << '\n';
        head++;    
    }
    
}

void PopBack()
{
    if(head == tail)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << d[tail-1] << '\n';
        tail--;
    }
}

void Size()
{
    cout << tail - head << '\n';
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
        cout << d[head] << '\n';
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
        cout << d[tail-1] << '\n';
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

        if(input == "push_front")
        {
            int x;
            cin >> x;
            PushFront(x);
        }
        else if(input == "push_back")
        {
            int x;
            cin >> x;
            PushBack(x);
        }
        else if(input == "pop_front")
        {
            PopFront();
        }
        else if(input == "pop_back")
        {
            PopBack();
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