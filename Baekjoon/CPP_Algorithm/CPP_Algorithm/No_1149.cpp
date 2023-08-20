#include <iostream>
#include <algorithm>

using namespace std;

int cost[1000][3]; // [i][j] [i]번째 집을 [j] 색으로 칠하는 비용
int d[1000][3]; // [i][j] [i]번째 집을 [j] 색으로 칠하게 될 때, 이뤄질 수 있는 누적 비용의 최솟값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> cost[i][j];
        }    
    }

    d[0][0] = cost[0][0];
    d[0][1] = cost[0][1];
    d[0][2] = cost[0][2];

    for(int i=1; i<n; i++)
    {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + cost[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + cost[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + cost[i][2];
    }

    cout << min({d[n-1][0], d[n-1][1], d[n-1][2]});
}