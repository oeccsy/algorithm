#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int num;
    int indegree = 0;
    vector<Node*> adj;
    bool is_visit = false;
};

Node* nodes[1001];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
    {
        nodes[i] = new Node();
        nodes[i]->num = i;
    }
    
    for(int i=0; i<m; i++)
    {
        vector<Node*> entry;
        int entry_size;
        cin >> entry_size;
        
        for(int j=0; j<entry_size; j++)
        {
            int input;
            cin >> input;
            
            Node* v = nodes[input];
            for(auto u : entry)
            {
                u->adj.push_back(v);
                v->indegree++;
            }
            
            entry.push_back(v);
        }
    }
    
    vector<Node*> sort_result;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(nodes[j]->is_visit) continue;
            if(nodes[j]->indegree != 0) continue;
            
            sort_result.push_back(nodes[j]);
            nodes[j]->is_visit = true;
            
            for(auto adj_node : nodes[j]->adj)
            {
                adj_node->indegree--;
            }
        }
    }
    
    if(sort_result.size() < n)
    {
        cout << 0;
    }
    else
    {
        for(auto node : sort_result)
        {
            cout << node->num << '\n';
        }    
    }
    
    for(int i=1; i<=n; i++)
    {
        delete nodes[i];
    }
}