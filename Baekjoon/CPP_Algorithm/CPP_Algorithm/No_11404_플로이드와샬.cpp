#include <iostream>
#include <algorithm>

#define INF 1000000000

using namespace std;

int graph[105][105];

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
            if(i==j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = INF;
            }
        }
    }
    
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u][v] = min(graph[u][v], w);
    }
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(graph[i][k] == INF || graph[k][j] == INF) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(graph[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << graph[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}