#include <iostream>
#include <algorithm>

using namespace std;

int num[100001];
int sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int idx=1; idx<=n; idx++)
    {
        cin >> num[idx];

        if(idx == 0)
        {
            sum[idx] = num[idx];
        }
        else
        {
            sum[idx] = sum[idx-1] + num[idx];
        }
    }

    for(int idx=1; idx<=m; idx++)
    {
        int i,j;
        cin >> i >> j;
        
        cout << sum[j] - sum[i-1] << '\n';
    }
}