#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    Node* parent = nullptr;
    vector<Node*> children;
    int dist = 0;
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

    queue<Node*> bfs_stack;
    root->parent = root;
    bfs_stack.push(root);

    while(!bfs_stack.empty())
    {
        Node* cur_node = bfs_stack.front();
        bfs_stack.pop();

        for(auto child : cur_node->children)
        {
            if(child->parent != nullptr) continue;
            child->parent = cur_node;
            child->dist = cur_node->dist + 1;
            bfs_stack.push(child);
        }
    }

    priority_queue<pair<int, Node*>> pq;
    
    for(int i=1; i<=n; i++)
    {
        pq.push({nodes[i]->dist, nodes[i]});
    }

    while(!pq.empty())
    {
        Node* cur_node = pq.top().second;
        pq.pop();

        for(auto child : cur_node->children)
        {
            if(child == cur_node->parent) continue;
            cur_node->total_sub_count += child->total_sub_count;
        }
    }

    for(int i=0; i<q; i++)
    {
        int target;
        cin >> target;
        cout << nodes[target]->total_sub_count << '\n';
    }
}