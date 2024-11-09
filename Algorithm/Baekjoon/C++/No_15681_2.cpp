#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    Node* parent = nullptr;
    vector<Node*> children;
    bool is_visit = false;
    int total_sub_count = 1;
};

Node* root;
Node* nodes[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;

    for(int i=1; i<=n; i++)
    {
        nodes[i] = new Node();
    }

    root = nodes[r];

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        nodes[u]->children.push_back(nodes[v]);
        nodes[v]->children.push_back(nodes[u]);
    }

    stack<Node*> dfs_stack;
    root->parent = root;
    dfs_stack.push(root);

    while(!dfs_stack.empty())
    {
        Node* cur_node = dfs_stack.top();
        
        if(!cur_node->is_visit)
        {
            for(auto child : cur_node->children)
            {
                if(child->parent != nullptr) continue;
                child->parent = cur_node;
                dfs_stack.push(child);
            }

            cur_node->is_visit = true;
        }
        else
        {
            dfs_stack.pop();

            for(auto child : cur_node->children)
            {
                if(child->parent != cur_node) continue;
                cur_node->total_sub_count += child->total_sub_count;
            }
        }
    }

    for(int i=0; i<q; i++)
    {
        int target;
        cin >> target;
        cout << nodes[target]->total_sub_count << '\n';
    }
}