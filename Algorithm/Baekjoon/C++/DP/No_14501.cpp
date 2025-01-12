#include <iostream>
#include <algorithm>

using namespace std;

int t[20];
int p[20];

int d[20];      //i일에 상담을 `처음` 시작 했을 때 얻을 수 있는 최댓값

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
            // 상담을 할 수 있다. 따라서 하는 경우와 안하는 경우로 나눈다.
            
            d[i] = max(d[i+1], d[i+t[i]] + p[i]);
            // 상담을 안하면 d[i] = d[i+1] 이다.
            // 상담을 하면   d[i] = d[i+t[i]] + p[i] 이다.
        }
        else
        {
            // 상담을 할 수 없다. 안하는 경우만 생각한다.
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