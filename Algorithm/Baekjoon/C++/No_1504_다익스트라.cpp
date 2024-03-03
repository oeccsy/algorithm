#include <iostream>
#include <queue>
#include <vector>

#define INF 2000000000

using namespace std;

int n, e;
int adj[801][801];
int dist[801][801];

long long cal_dist(int st, int en)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dist[i][j] = INF;
        }
    }
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    dist[st][st] = 0;
    pq.push({dist[st][st], st});

    while(!pq.empty())
    {
        int min_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(min_dist != dist[st][cur_node]) continue;
        
        for(int adj_node=1; adj_node<=n; adj_node++)
        {
            if(adj[cur_node][adj_node] == INF) continue;
            if(dist[st][adj_node] <= min_dist + adj[cur_node][adj_node]) continue;

            dist[st][adj_node] = min_dist + adj[cur_node][adj_node];
            pq.push({dist[st][adj_node], adj_node});
        }
    }

    return dist[st][en];
}

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
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INF;
            }
        }
    }

    for(int i=0; i<e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }

    int v1, v2;
    cin >> v1 >> v2;
    
    long long answer = min(cal_dist(1,v1) + cal_dist(v1,v2) + cal_dist(v2,n), cal_dist(1,v2) + cal_dist(v2,v1) + cal_dist(v1,n));
    if(answer >= INF) answer = -1;

    cout << answer;
}