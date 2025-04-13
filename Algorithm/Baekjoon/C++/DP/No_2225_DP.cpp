#include <iostream>

using namespace std;

int n;
int k;

int d[205][205];

int solve(int sum, int depth)
{
    if(sum > n) return 0;
    if(d[sum][depth] >= 0) return d[sum][depth];

    if(depth == k - 1)
    {
        d[sum][depth] = 1;
        return 1;
    }

    int count = 0;

    for(int i=0; i<=n; i++)
    {
        count += solve(sum + i, depth + 1);
        count = count % 1000000000;
    }

    d[sum][depth] = count;
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            d[i][j] = -1;
        }
    }
    
    cout << solve(0, 0);
}