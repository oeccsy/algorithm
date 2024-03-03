#include <iostream>
#include <queue>
#include <vector>

#define INF 1000000000

using namespace std;

struct Node;
struct Edge;

struct Node
{
    int num;
    int cost_to_home;
    int cost_to_x;
    int cost_temp;
    vector<Edge*> adj;
};

struct Edge
{
    int weight;
    Node* adj_node;
};

Node* nodes[1001];

int cost(int st, int en)
{
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int,Node*>>> pq;
    nodes[st]->cost_temp = 0;
    pq.push({nodes[st]->cost_temp, nodes[st]});

    while(!pq.empty())
    {
        int min_cost = pq.top().first;
        Node* cur_node = pq.top().second;
        pq.pop();

        if(min_cost != cur_node->cost_temp) continue;

        for(auto edge : cur_node->adj)
        {
            int weight = edge->weight;
            Node* adj_node = edge->adj_node;

            if(adj_node->cost_temp <= min_cost + weight) continue;

            adj_node->cost_temp = min_cost + weight;
            pq.push({adj_node->cost_temp, adj_node});
        }
    }

    return nodes[en]->cost_temp;
}

void solve_cost_to_home(int x)
{
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int,Node*>>> pq;
    nodes[x]->cost_to_home = 0;
    pq.push({nodes[x]->cost_to_home, nodes[x]});

    while(!pq.empty())
    {
        int min_cost = pq.top().first;
        Node* cur_node = pq.top().second;
        pq.pop();

        if(min_cost != cur_node->cost_to_home) continue;

        for(auto edge : cur_node->adj)
        {
            int weight = edge->weight;
            Node* adj_node = edge->adj_node;

            if(adj_node->cost_to_home <= min_cost + weight) continue;

            adj_node->cost_to_home = min_cost + weight;
            pq.push({adj_node->cost_to_home, adj_node});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    for(int i=1; i<=n; i++)
    {
        nodes[i] = new Node();
        nodes[i]->num = i;
        nodes[i]->cost_to_home = INF;
        nodes[i]->cost_to_x = INF;
        nodes[i]->cost_temp = INF;
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

    solve_cost_to_home(x);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            nodes[j]->cost_temp = INF;
        }

        nodes[i]->cost_to_x = cost(i, x);
    }
    
    int max_cost = 0;
    for(int i=1; i<=n; i++)
    {
        max_cost = max(max_cost, nodes[i]->cost_to_home + nodes[i]->cost_to_x);
    }

    cout << max_cost;
}