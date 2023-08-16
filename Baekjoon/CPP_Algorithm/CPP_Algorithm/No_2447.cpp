#include <iostream>

using namespace std;

bool clear[10000][10000];

void SetCenterEmpty(int start_row, int start_col, int n)
{
    for(int i=start_row + n/3; i < start_row + n/3 + n/3; i++)
    {
        for(int j=start_col + n/3; j < start_col + n/3 + n/3; j++)
        {
            clear[i][j] = true;
        }
    }
    
    if(n == 1)
    {
        return;
    }
    else
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                SetCenterEmpty(start_row + n/3 * i, start_col + n/3 * j, n/3);    
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    SetCenterEmpty(0, 0, n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(clear[i][j])
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << '\n';
    }
}