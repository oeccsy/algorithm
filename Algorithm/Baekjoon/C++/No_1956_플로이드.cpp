#include <iostream>

#define INF 2000000000

using namespace std;

int n, e;
int dist[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_cycle = INF;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(dist[i][j] == INF || dist[j][i] == INF) continue;
            if(dist[i][j] + dist[j][i] < min_cycle) min_cycle = dist[i][j] + dist[j][i]; 
        }
    }

    if(min_cycle == INF) min_cycle = -1;

    cout << min_cycle;
}