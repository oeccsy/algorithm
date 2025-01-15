#include <iostream>

using namespace std;

int n,m;
int selected[8];

void Count(int index)
{
    if(index == m)
    {
        for(int i=0; i<m; i++)
        {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(index != 0 && selected[index - 1] > i) continue;
        selected[index] = i;
        Count(index+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    Count(0);
}