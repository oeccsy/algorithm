#include <iostream>
#include <deque>

using namespace std;

struct Node
{
    int index;
    int number;
};

deque<Node> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,l;

    cin >> n >> l;
    
    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;

        Node new_node = {i, input};

        while(!a.empty())
        {
            if(a.front().index < i-l+1)
            {
                a.pop_front();
            }
            else if(a.back().index < i-l+1)
            {
                a.pop_back();
            }
            else if(a.back().number < new_node.number)
            {
                a.push_back(new_node);
                break;
            }
            else if(a.back().number >= new_node.number)
            {
                a.pop_back();
            }
        }

        if(a.empty())
        {
            a.push_back(new_node);
        }

        cout << a.front().number << " ";
    }
}