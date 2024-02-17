#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int num;
    int indegree = 0;

    vector<Node*> adj;
    vector<int> cost;

    bool is_visit = false;
    bool is_middle_mat = false;
};

Node* nodes[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        nodes[i] = new Node();
        nodes[i]->num = i;
        nodes[i]->cost.assign(n+1, 0);
    }

    cin >> m;
    for(int i=0; i<m; i++)
    {
        int x, y ,k;
        cin >> x >> y >> k;

        nodes[y]->adj.push_back(nodes[x]);
        nodes[x]->indegree++;
        nodes[x]->cost[y] += k;
        nodes[x]->is_middle_mat = true;
    }

    int visit_count = 0;
    while(visit_count < n)
    {
        for(int i=1; i<=n; i++)
        {
            if(nodes[i]->indegree > 0) continue;
            if(nodes[i]->is_visit) continue;

            nodes[i]->is_visit = true;
            visit_count++;
            
            for(auto adj_node : nodes[i]->adj)
            {
                adj_node->indegree--;

                if(!nodes[i]->is_middle_mat) continue;
                
                int count = adj_node->cost[i];
                adj_node->cost[i] = 0;

                for(int j=1; j<=n; j++)
                {
                    adj_node->cost[j] += nodes[i]->cost[j] * count;
                }
            }
            break;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(nodes[i]->is_middle_mat) continue;
        cout << i << ' ' << nodes[n]->cost[i] << '\n';
    }
}