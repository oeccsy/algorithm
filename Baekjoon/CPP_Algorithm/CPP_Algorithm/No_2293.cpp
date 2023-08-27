#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int cost[100];
int d[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> cost[i];
    }

    // d[] 를 채우는 순서가 중요함.
    // 아래 반복문의 i, j의 순환 순서가 바뀌면 결과도 바뀜
    for(int j=0; j<n; j++)
    {
        if(cost[j] <= 10000) d[cost[j]] += 1;
        for(int i=2; i<=k; i++)
        {
            if(i-cost[j] > 0)
            {
                d[i] += d[i-cost[j]];
            }
        }
    }

    

    cout << d[k];
}