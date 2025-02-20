#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node;
struct Edge;

struct Node
{
    int num;
    vector<Edge*> adj;

    bool is_used = false;
};

struct Edge
{
    int cost;
    Node* src;
    Node* dest;
};

struct Cmp
{
    bool operator()(Edge* a, Edge* b)
    {
        return (a->cost) > (b->cost);
    }  
};

Node* nodes[100005];
int max_cost = 0;
int total_cost = 0;

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
    }

    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        Edge* a_to_b_edge = new Edge();
        a_to_b_edge->src = nodes[a];
        a_to_b_edge->dest = nodes[b];
        a_to_b_edge->cost = c;
        nodes[a]->adj.push_back(a_to_b_edge);

        Edge* b_to_a_edge = new Edge();
        b_to_a_edge->src = nodes[b];
        b_to_a_edge->dest = nodes[a];
        b_to_a_edge->cost = c;
        nodes[b]->adj.push_back(b_to_a_edge);
    }

    priority_queue<Edge*, vector<Edge*>, Cmp> pq;
    nodes[1]->is_used = true;

    for(auto edge : nodes[1]->adj)
    {
        pq.push(edge);
    }

    for(int i=0; i<n-1; i++)
    {
        Edge* min_cost_edge;

        while(!pq.empty())
        {
            min_cost_edge = pq.top();
            pq.pop();

            if(min_cost_edge->dest->is_used)
            {
                continue;
            } 
            else
            {
                break;
            }
        }

        max_cost = max(max_cost, min_cost_edge->cost);
        total_cost += min_cost_edge->cost;
        min_cost_edge->dest->is_used = true;

        for(auto edge : min_cost_edge->dest->adj)
        {
            pq.push(edge);
        }
    }

    cout << total_cost - max_cost;
}