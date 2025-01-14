#include <iostream>
#include <vector>

using namespace std;

int answer_a = 0;
int answer_b = 0;

void find_answer_a(int m)
{
    if(m == 1)
    {
        answer_a = 1;
        return;
    }

    int len = m / 3;
    if(m % 3 == 1 || m % 3 == 2) len++;

    answer_a = len;
}

void find_answer_b(int m)
{
    if(m == 1)
    {
        answer_b = 1;
        return;
    }
    
    int len = 0;
    int cur = m;

    while(cur % 4 == 0)
    {
        cur /= 4;
        len++;
    }

    for(int i=2; i<=m; i++)
    {
        while(cur % i == 0)
        {
            cur /= i;
            len++;
        }

        if(cur == 1) break;
    }

    answer_b = len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    cin >> m;

    find_answer_a(m);
    find_answer_b(m);

    cout << answer_a << " " << answer_b;
}