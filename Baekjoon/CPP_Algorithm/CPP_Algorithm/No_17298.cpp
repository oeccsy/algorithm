#include <iostream>
#include <stack>

using namespace std;

struct Number
{
    int index;
    int number;
};

int nge[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    stack<Number> a;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        Number number;
        number.index = i;
        number.number = input;

        while (!a.empty())
        {
            if (a.top().number < input)
            {
                nge[a.top().index] = input;
                a.pop();
            }
            else
            {
                break;
            }
        }

        a.push(number);
    }

    while (!a.empty())
    {
        nge[a.top().index] = -1;
        a.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    }
}
