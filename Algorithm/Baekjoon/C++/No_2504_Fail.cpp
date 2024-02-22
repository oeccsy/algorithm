#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node
{
    char symbol;
    int value;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<Node> s;
    int total_value = 0;
    
    string input;
    cin >> input;

    for(const auto c : input)
    {
        Node new_node = {c, 0};

        if(c == ')')
        {
            if(s.empty() || s.top().symbol == '[')
            {
                total_value = 0;
                break;
            }
            else if(s.top().symbol == '(')
            {
                new_node.symbol = 'x';
                new_node.value = 2;
                s.pop();

                if(!s.empty() && s.top().symbol == 'x')
                {
                    new_node.value += s.top().value;
                    s.pop();
                }
            }
            else if(s.top().symbol == 'x')
            {
                Node x = s.top();
                s.pop();

                if(s.empty() || s.top().symbol == '[')
                {
                    total_value = 0;
                    break;
                }
                else if(s.top().symbol == '(')
                {
                    new_node.symbol = 'x';
                    new_node.value = 2*x.value;
                    s.pop();
                }
            }
        }
        else if(c == ']')
        {
            if(s.empty() || s.top().symbol == '(')
            {
                total_value = 0;
                break;
            }
            else if(s.top().symbol == '[')
            {
                new_node.symbol = 'x';
                new_node.value = 3;
                s.pop();

                if(!s.empty() && s.top().symbol == 'x')
                {
                    new_node.value += s.top().value;
                    s.pop();
                }
            }
            else if(s.top().symbol == 'x')
            {
                Node x = s.top();
                s.pop();

                if(s.empty() || s.top().symbol == '(')
                {
                    total_value = 0;
                    break;
                }
                else if(s.top().symbol == '[')
                {
                    new_node.symbol = 'x';
                    new_node.value = 3*x.value;
                    s.pop();
                }
            }
        }

        s.push(new_node);
    }

    while(!s.empty())
    {
        if(s.top().symbol != 'x')
        {
            total_value = 0;
            break;
        }
        else
        {
            total_value += s.top().value;
            s.pop();   
        }
    }

    cout << total_value;
}