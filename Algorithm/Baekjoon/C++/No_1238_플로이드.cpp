#include <iostream>
#include <queue>
#include <vector>

#define INF 1000000000

using namespace std;

int cost[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
            {
                cost[i][j] = 0;   
            }
            else
            {
                cost[i][j] = INF;   
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        cost[u][v] = min(cost[u][v], w);
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    int answer = 0;
    for(int i=1; i<=n; i++)
    {
        answer = max(answer, cost[i][x] + cost[x][i]);
    }

    cout << answer;
}