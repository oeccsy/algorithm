#include <iostream>
#include <algorithm>

using namespace std;

int t[1500001];
int p[1500001];

int d[1500001];      //i일에 상담을 `처음` 시작 했을 때 얻을 수 있는 최댓값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> t[i] >> p[i];
    }
    
    for(int i=n; i>0; i--)
    {
        if(i+t[i] <= n + 1)
        {
            d[i] = max(d[i+1], d[i+t[i]] + p[i]);
        }
        else
        {
            d[i] = d[i+1];
        }
    }

    int result = 0;

    for(int i=1; i<=n; i++)
    {
        if(result < d[i]) result = d[i];
    }

    cout << result;
}