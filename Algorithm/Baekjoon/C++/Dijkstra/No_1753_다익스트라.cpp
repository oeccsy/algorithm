#include <iostream>
#include <vector>
#include <queue>

const int INF =  0x3f3f3f3f;

using namespace std;

struct Node
{
    int min_dist = INF;
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
    }
    
    for(int i=0; i<e; i++)
    {
        int input_u, input_v, input_w;
        cin >> input_u >> input_v >> input_w;
        
        nodes[input_u]->adj.push_back({input_w, nodes[input_v]});
    }
    
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int,Node*>>> pq;
    nodes[k]->min_dist = 0;
    pq.push({0, nodes[k]});
    
    while(!pq.empty())
    {
        Node* cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();
        
        if(cur_dist != cur_node->min_dist) continue;
        
        for(auto adj_info : cur_node->adj)
        {
            Node* dest_node = adj_info.second;
            int weight = adj_info.first;
            
            if(cur_node->min_dist + weight >= dest_node->min_dist) continue;
            
            dest_node->min_dist = cur_node->min_dist + weight;
            pq.push({dest_node->min_dist, dest_node});
        }
    }
    
    for(int i = 1; i <= v; i++)
    {
        if(nodes[i]->min_dist == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << nodes[i]->min_dist << "\n";
        }
    }
}