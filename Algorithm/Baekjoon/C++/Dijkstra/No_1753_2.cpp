#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Node
{
    int dist = INF;
    vector<pair<int, Node*>> adj;
};


Node* nodes[20005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    int k;

    cin >> v >> e;
    cin >> k;

    for(int i=1; i<=v; i++)
    {
        nodes[i] = new Node();
    }

    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
 
        nodes[u]->adj.emplace_back(w, nodes[v]);
    }

    priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
    nodes[k]->dist = 0;
    pq.push({0, nodes[k]});

    while(!pq.empty())
    {
        int min_dist = pq.top().first;
        Node* node = pq.top().second;
        pq.pop();

        if(min_dist != node->dist) continue;

        for(auto& edge : node->adj)
        {
            int weight = edge.first;
            Node* adj_node = edge.second;
            
            if(adj_node->dist <= min_dist + weight) continue;

            adj_node->dist = min_dist + weight;
            pq.push({adj_node->dist, adj_node});
        }
    }

    for(int i=1; i<=v; i++)
    {
        if(nodes[i]->dist == INF)
        {   
            cout << "INF" << '\n';
        }
        else
        {
            cout << nodes[i]->dist << '\n';
        }
    }
}