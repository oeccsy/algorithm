#include <iostream>

#define INF 2000000000

using namespace std;

int dist[201][201];
int best_next[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = w;
        dist[v][u] = w;
        best_next[u][v] = v;
        best_next[v][u] = u;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                if(dist[i][j] <= dist[i][k] + dist[k][j]) continue;

                dist[i][j] = dist[i][k] + dist[k][j];
                best_next[i][j] = best_next[i][k];
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(best_next[i][j] == 0)
            {
                cout << '-' << ' ';
            }
            else
            {
                cout << best_next[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}