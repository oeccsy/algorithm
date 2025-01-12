#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int num;
    vector<Node*> adj;
    int indegree = 0;
    bool is_visit = false;
};

Node* nodes[32001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        nodes[i] = new Node();
        nodes[i]-> num = i;
    }
    
    for(int i=0; i<m; i++)
    {
        int u_index, v_index;
        cin >> u_index >> v_index;

        Node* u = nodes[u_index];
        Node* v = nodes[v_index];

        u->adj.push_back(v);
        v->indegree++;
    }

    int visit_count = 0;

    while(visit_count < n)
    {
        for(int i=1; i<=n; i++)
        {
            Node* node = nodes[i];

            if(node->indegree > 0) continue;
            if(node->is_visit) continue;

            node->is_visit = true;
            visit_count++;
            
            cout << node->num << ' ';

            for(auto adj_node : node->adj)
            {
                adj_node->indegree--;
            }
            
            break;
        }
    }
}