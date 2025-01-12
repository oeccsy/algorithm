#include <iostream>

#define INF 2000000000

using namespace std;

int max_height[301][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j)
            {
                max_height[i][j] = 0;
            }
            else
            {
                max_height[i][j] = INF;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        int u, v, h;
        cin >> u >> v >> h;

        max_height[u][v] = h;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(max_height[i][k] == INF || max_height[k][j] == INF) continue;
                if(max_height[i][k] >= max_height[i][j] || max_height[k][j] >= max_height[i][j]) continue;

                max_height[i][j] = max(max_height[i][k], max_height[k][j]);
            }
        }
    }

    for(int i=0; i<t; i++)
    {
        int s, e;
        cin >> s >> e;

        if(max_height[s][e] == INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << max_height[s][e] << '\n';
        }
    }
}