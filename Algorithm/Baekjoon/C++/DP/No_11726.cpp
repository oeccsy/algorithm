#include <iostream>
#include <algorithm>

using namespace std;

long long d[1000][3]; // i번째가  0 : 세로 배치,  1 : 가로 배치 (시작),  2 : 가로 배치 (종료) 일 때 최소 가짓 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    d[0][0] = 1;
    
    if(0 + 1 < n)
    {
        d[0][1] = 1;
        d[0][2] = 0;
    }
    
    
    for(int i=1; i<n; i++)
    {
        d[i][0] = (d[i-1][0] + d[i-1][2]) % 10007;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % 10007;
        d[i][2] = d[i-1][1];
    }

    cout << (d[n-1][0] + d[n-1][2]) % 10007;
}