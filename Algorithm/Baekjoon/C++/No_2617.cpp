#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    int data;
    int greater_count;
    int less_count;
    vector<Node*> adj;
    bool is_visit;
    bool is_impossible;
};

Node nodes[105];

void dfs(Node* root)
{
    for(auto& node : nodes) node.is_visit=false;

    root->is_visit=true;
    stack<Node*> stack;
    stack.push(root);
    
    while(!stack.empty())
    {
        Node* cur_node=stack.top();
        stack.pop();
        
        for(auto it=cur_node->adj.begin(); it!=cur_node->adj.end(); it++)
        {
            Node* adj_node=*it;
            if(adj_node->is_visit) continue;
            
            adj_node->is_visit=true;
            stack.push(adj_node);
            
            root->less_count++;
            adj_node->greater_count++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;

    for(int i=0; i<=n; i++)
    {
        nodes[i].data = i;
    }
    
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        nodes[a].adj.push_back(&nodes[b]);
    }
    
    int result=0;
    int mid=(n+1)/2;
    
    for(int i=1; i<=n; i++)
    {
        dfs(&nodes[i]);
    }
    
    for(int i=1; i<=n; i++)
    {
        if(nodes[i].greater_count >= mid || nodes[i].less_count >= mid) result++;
    }
    
    cout << result;
}