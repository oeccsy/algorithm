#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Node
{
    int index;
    int dist = INF;
    vector<pair<int, Node*>> adj;
};

Node* nodes[20005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, k;
    cin >> v >> e;
    cin >> k;

    for(int i=1; i<=v; i++)
    {
        nodes[i] = new Node();
        nodes[i]->index = i;
    }

    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u]->adj.push_back({w,nodes[v]});
    }

    priority_queue<pair<int, Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
    nodes[k]->dist = 0;
    pq.push({nodes[k]->dist, nodes[k]});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(cur.second->dist != cur.first) continue;

        for(auto adj_info : cur.second->adj)
        {
            if(adj_info.second->dist <= cur.second->dist + adj_info.first) continue;

            adj_info.second->dist = cur.second->dist + adj_info.first;
            pq.push({adj_info.second->dist, adj_info.second});
        }
    }
    
    for(int i = 1; i <= v; i++)
    {
        if(nodes[i]->dist == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << nodes[i]->dist << "\n";
        }
    }
}