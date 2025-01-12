#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n, m;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        int d[10005];
        vector<int> coins;

        for(int j=0; j<n; j++)
        {
            int coin_value;
            cin >> coin_value;
            coins.push_back(coin_value);
        }

        cin >> m;
        for(int j=0; j<=m; j++) d[j] = 0;
        d[0] = 1;
        
        for(auto coin_value : coins)
        {
            for(int j=1; j<=m; j++)
            {
                if(coin_value > j) continue;
                d[j] += d[j-coin_value];
            }
        }

        cout << d[m] << '\n';
    }
}