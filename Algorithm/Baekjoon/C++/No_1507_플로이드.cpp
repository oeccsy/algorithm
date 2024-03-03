#include <iostream>

#define INF 2000000000

using namespace std;

int n;
int dist[21][21];
int real_dist[21][21];
bool adj[21][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
            real_dist[i][j] = INF;
            if(i != j) adj[i][j] = true;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i == j || j == k || k == i) continue;
                
                if(dist[i][j] == dist[i][k] + dist[k][j])
                {
                    adj[i][j] = false;    
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(adj[i][j]) real_dist[i][j] = dist[i][j];
            if(i==j) real_dist[i][j] = 0;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(real_dist[i][k] == INF || real_dist[k][j] == INF) continue;
                real_dist[i][j] = min(real_dist[i][j], real_dist[i][k] + real_dist[k][j]);
            }
        }
    }

    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j] != real_dist[i][j])
            {
                cout << -1;
                return 0;
            }

            if(adj[i][j]) sum += dist[i][j];
        }
    }

    cout << sum / 2;
}