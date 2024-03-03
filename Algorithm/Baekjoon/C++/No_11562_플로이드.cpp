#include <iostream>

#define INF 2000000000

using namespace std;

int n, m;
int dist[251][251];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
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

    for (int i = 0; i < m; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;

        if(b == 0)
        {
            dist[u][v] = 0;
            dist[v][u] = 1;
        }
        else if(b == 1)
        {
            dist[u][v] = 0;
            dist[v][u] = 0;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                if(dist[i][j] <= dist[i][k] + dist[k][j]) continue;
                    
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int k;
    cin >> k;
    for(int i=0; i<k; i++)
    {
        int s, e;
        cin >> s >> e;

        cout << dist[s][e] << '\n';
    }
}