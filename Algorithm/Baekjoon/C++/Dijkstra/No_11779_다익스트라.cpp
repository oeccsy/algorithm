#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define INF 1000000000

using namespace std;

struct Node;
struct Edge;

struct Node
{
    int num;
    int cost;
    vector<Edge*> adj;
};

struct Edge
{
    int weight;
    Node* adj_node;
};

Node* nodes[1001];
int best_prev[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        nodes[i] = new Node();
        nodes[i]->num = i;
        nodes[i]->cost = INF;
    }

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        Edge* new_edge = new Edge();
        new_edge->weight = w;
        new_edge->adj_node = nodes[v];

        nodes[u]->adj.push_back(new_edge);
    }

    int st, en;
    cin >> st >> en;

    priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
    nodes[st]->cost = 0;
    pq.push({nodes[st]->cost, nodes[st]});

    while(!pq.empty())
    {
        int min_cost = pq.top().first;
        Node* cur_node = pq.top().second;
        pq.pop();

        if(min_cost != cur_node->cost) continue;

        for(auto edge : cur_node->adj)
        {
            int weight = edge->weight;
            Node* adj_node = edge->adj_node;

            if(adj_node->cost <= min_cost + weight) continue;

            best_prev[adj_node->num] = cur_node->num;
            adj_node->cost = min_cost + weight;
            pq.push({adj_node->cost, adj_node});
        }
    }

    stack<int> path;
    int node_num = en;
    while(node_num != 0)
    {
        path.push(node_num);
        node_num = best_prev[node_num];
    }
    
    cout << nodes[en]->cost << '\n';
    cout << path.size() << '\n';
    while(!path.empty())
    {
        cout << path.top() << ' ';
        path.pop();
    }
}