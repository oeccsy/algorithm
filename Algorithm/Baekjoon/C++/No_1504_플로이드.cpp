#include <iostream>

#define INF 2000000000

using namespace std;

int n, e;
int dist[801][801];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> e;
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

    for(int i=0; i<e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int v1,v2;
    cin >> v1 >> v2;
    
    long long answer = min((long long)dist[1][v1] + dist[v1][v2] + dist[v2][n], (long long)dist[1][v2] + dist[v2][v1] + dist[v1][n]);
    if(answer >= INF) answer = -1;

    cout << answer;
}