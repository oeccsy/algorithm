#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000000

using namespace std;

int n, m;
int k;
int friends[201];
int dist[201][201];

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
        int a, b, t;
        cin >> a >> b >> t;

        dist[a][b] = min(dist[a][b], t);
    }

    cin >> k;
    for(int i=0; i<k; i++)
    {
        cin >> friends[i];
    }
    
    for (int h = 1; h <= n; h++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][h] == INF || dist[h][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][h] + dist[h][j]);
            }
        }
    }

    int x_dist = INF;
    vector<int> x;
    
    for(int i=1; i<=n; i++)
    {
        int max_dist = 0;
        for(int j=0; j<k; j++)
        {
            int home = friends[j];
            max_dist = max(max_dist, dist[i][home] + dist[home][i]);
        }

        if(max_dist < x_dist)
        {
            x_dist = max_dist;
            x.clear();
            x.push_back(i);
        }
        else if(max_dist == x_dist)
        {
            x.push_back(i);
        }
    }

    sort(x.begin(), x.end());

    for(int i=0; i<x.size(); i++)
    {
        cout << x[i] << ' ';
    }
}