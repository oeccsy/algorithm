#include <iostream>

using namespace std;

int d[10001];
int coin[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int n, target;
        cin >> n;

        for(int j=0; j<n; j++)
        {
            cin >> coin[j];
        }
        
        cin >> target;

        for(int j=0; j<n; j++)
        {
            d[coin[j]] += 1;

            for(int k=coin[j]+1; k<=target; k++)
            {
                d[k] += d[k-coin[j]];
            }
        }

        cout << d[target] << '\n';

        for(int k=1; k<=target; k++)
        {
            d[k] = 0;
        }
    }
}