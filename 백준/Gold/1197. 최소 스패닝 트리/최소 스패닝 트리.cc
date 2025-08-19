#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    vector<pair<int,Node*>> adj;
    bool is_used = false;
};

Node* nodes[10005];
int answer = 0;
int count = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    for(int i=1; i<=v; i++)
    {
        nodes[i] = new Node();
    }

    for(int i=0; i<e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        nodes[a]->adj.emplace_back(c, nodes[b]);
        nodes[b]->adj.emplace_back(c, nodes[a]);
    }

    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    nodes[1]->is_used = true;
    
    for(auto& edge : nodes[1]->adj)
    {
        pq.push(edge);
    }

    while(!pq.empty())
    {
        int weight = pq.top().first;
        Node* dest = pq.top().second;
        pq.pop();

        if(dest->is_used) continue;

        answer += weight;
        dest->is_used = true;
        
        for(auto& edge : dest->adj)
        {
            pq.push(edge);
        }
    }

    cout << answer;
}