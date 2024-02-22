#include <iostream>

using namespace std;

int d[1000001][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for(int i=2; i<=n; i++)
    {
        d[i][0] = d[i-1][0] + 1;
        d[i][1] = i-1;
        
        if(i%3==0 && d[i/3][0]+1 < d[i][0])
        {
            d[i][0] = d[i/3][0] + 1;
            d[i][1] = i/3;
        }
        if(i%2==0 && d[i/2][0]+1 < d[i][0])
        {
            d[i][0] = d[i/2][0] + 1;
            d[i][1] = i/2;
        }
    }

    cout << d[n][0] << '\n';

    while (n > 0)
    {
        cout << n << " ";
        n = d[n][1];
    }
}