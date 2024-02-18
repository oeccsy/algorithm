#include <iostream>
#include <algorithm>

using namespace std;

int d[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> d[i];
    }

    int max = 0;

    for(int i=1; i<=n; i++)
    {
        if(d[i] > max) max = d[i];
        
        for(int j=i+1; j<=n; j++)
        {
            d[i] = d[i]+d[j];
            if(d[i] > max) max = d[i];
        }
    }

    cout << max;
}