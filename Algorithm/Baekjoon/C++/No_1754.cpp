#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int node_num;
    int min_dist;
    vector<pair<int, Node*>> adj;
};

Node nodes[20005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int v, e;
    cin >> v >> e;
    
    int k;
    cin >> k;
    
    for(int i=1; i<=v; i++)
    {
        nodes[i].node_num = i;
        nodes[i].min_dist = 0x3f3f3f3f;
    }
    
    for(int i=1; i<=e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        nodes[u].adj.push_back({w, &nodes[v]} );
    }
    
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    nodes[k].min_dist = 0;
    pq.push({0, &nodes[k]});
    
    while(!pq.empty())
    {
        pair<int, Node*> cur_data = pq.top();
        pq.pop();
        
        if(cur_data.first != cur_data.second->min_dist) continue;
        
        for(auto adj_data : cur_data.second->adj)
        {
            if(adj_data.second->min_dist <= cur_data.second->min_dist + adj_data.first) continue;
            adj_data.second->min_dist = cur_data.second->min_dist + adj_data.first;
            pq.push({adj_data.second->min_dist, adj_data.second});
        }
    }
    
    for(int i=1; i<=v; i++)
    {
        if(nodes[i].min_dist != 0x3f3f3f3f) cout << nodes[i].min_dist << '\n';
        if(nodes[i].min_dist == 0x3f3f3f3f) cout << "INF" << '\n';
    }
}