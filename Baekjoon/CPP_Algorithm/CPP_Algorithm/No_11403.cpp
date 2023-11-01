#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Node
{
    int data;
    vector<Node*> adj;
    bool is_visit;
};

Node nodes[105];

bool dfs_until_find_path(int i, int j)
{
    Node* root = &nodes[i];
    //root->is_visit = true;
    
    stack<Node*> stack;
    stack.push(root);
    
    while(!stack.empty())
    {
        Node* cur_node = stack.top();
        stack.pop();
        
        for(auto it=cur_node->adj.begin(); it!=cur_node->adj.end(); it++)
        {
            Node* adj_node = *it;
            if(adj_node->data == j) return true;
            if(adj_node->is_visit) continue;

            adj_node->is_visit = true;
            stack.push(adj_node);
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        nodes[i].data = i;
        
        for(int j=0; j<n; j++)
        {
            int input;
            cin >> input;
            
            if(input == 1) nodes[i].adj.push_back(&nodes[j]);
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(auto& node : nodes)
            {
                node.is_visit = false;
            }
            
            if(dfs_until_find_path(i, j))
                cout << 1 << " ";
            else
                cout << 0 << " ";

        }
        cout << '\n';
    }
}