#include <iostream>

#define INF 2000000000

using namespace std;

int n, m, r;
int item[101];
int item_count[101];
int dist[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }

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

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;

        dist[a][b] = min(dist[a][b], l);
        dist[b][a] = min(dist[b][a], l);
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
    
    int max_item_count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dist[i][j] <= m) item_count[i] += item[j];
        }

        if(max_item_count < item_count[i]) max_item_count = item_count[i];
    }

    cout << max_item_count;
}
