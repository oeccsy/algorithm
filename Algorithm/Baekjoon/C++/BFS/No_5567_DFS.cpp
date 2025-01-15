#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int data;
    int depth;
    vector<Node*> adj;
    bool is_visit;
};

Node nodes[505];
int result = 0;

void dfs(int start_index)
{
    Node* root = &nodes[start_index];
    stack<Node*> stack;
    stack.push(root);

    root->is_visit = true;
    
    while(!stack.empty())
    {
        Node* cur_node = stack.top();
        stack.pop();

        for(auto it = cur_node->adj.begin(); it!=cur_node->adj.end(); it++)
        {
            Node* adj_node = *it;
            if(adj_node->is_visit) continue;
            
            adj_node->is_visit = true;
            adj_node->depth = cur_node->depth + 1;
            result++;
            
            if(adj_node->depth == 2) continue;
            stack.push(adj_node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;

    for(int i=0; i<505; i++)
    {
        nodes[i].data = i;
    }
    
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        nodes[a].adj.push_back(&nodes[b]);
        nodes[b].adj.push_back(&nodes[a]);
    }

    dfs(1);
    
    cout << result;
}
