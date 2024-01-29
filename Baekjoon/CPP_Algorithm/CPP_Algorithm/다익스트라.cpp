#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int node_num;
    bool is_fix;
    vector<pair<Node*, int>> adj;
};

int dist[20005];
Node nodes[20005];

int main()
{
    int v, e;
    cin >> v >> e;
    
    int k;
    cin >> k;
    
    for(int i=0; i<=v; i++)
    {
        dist[i] = 100;
        nodes[i].node_num = i;
    }
    
    dist[k] = 0;
    
    for(int i=0; i<e; i++)
    {
        int u_input, v_input, w_input;
        cin >> u_input >> v_input >> w_input;
        
        nodes[u_input].adj.push_back(make_pair(&nodes[v_input], w_input));
    }
    
    while(true)
    {
        Node* close_node = nullptr;
        for(int i=1; i<=v; i++)
        {
            if(nodes[i].is_fix) continue;
            if(close_node == nullptr) close_node = &nodes[i];
            else if(dist[i] < dist[close_node->node_num]) close_node = &nodes[i];
        }
        
        if(close_node == nullptr || dist[close_node->node_num] == 100) break;
        
        close_node->is_fix = true;
        for(auto edge : close_node->adj)
        {
            dist[edge.first->node_num] = min(dist[edge.first->node_num], dist[close_node->node_num] + edge.second);
        }
    }
    
    for(int i=1; i<=v; i++)
    {
        if(dist[i] != 100) cout << dist[i] << '\n';
        if(dist[i] == 100) cout << "INF" << '\n';
    }
}