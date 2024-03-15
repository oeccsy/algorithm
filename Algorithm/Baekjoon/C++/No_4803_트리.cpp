#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node
{
    int index;
    Node* parent;
    vector<Node*> adj;
};

Node* nodes[505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int repeat = 0;
    while(++repeat)
    {
        int n, m;
        cin >> n >> m;

        if(n==0 && m==0) break;

        for(int i=1; i<=n; i++)
        {
            nodes[i] = new Node();
            nodes[i]->index = i;
        }
        
        for(int i=0; i<m; i++)
        {
            int u, v;
            cin >> u >> v;

            nodes[u]->adj.push_back(nodes[v]);
            nodes[v]->adj.push_back(nodes[u]);
        }

        int tree_count = 0;
        for(int i=1; i<=n; i++)
        {
            if(nodes[i]->parent != nullptr) continue;

            int node_count = 0;
            int edge_count = 0;
            stack<Node*> stack;
            nodes[i]->parent = nodes[i];
            node_count++;
            edge_count += nodes[i]->adj.size();
            stack.push(nodes[i]);

            while(!stack.empty())
            {
                Node* cur_node = stack.top();
                stack.pop();

                for(const auto adj_node : cur_node->adj)
                {
                    if(adj_node->parent != nullptr || cur_node->parent == adj_node) continue;
                    adj_node->parent = cur_node;
                    node_count++;
                    edge_count += adj_node->adj.size() - 1;
                    stack.push(adj_node);
                }
            }
            
            if(edge_count == node_count-1) tree_count++;
        }

        cout << "Case " << repeat << ": ";
        switch(tree_count)
        {
            case 0:
                cout << "No trees." << '\n';
                break;
            case 1:
                cout << "There is one tree." << '\n';
                break;
            default:
                cout << "A forest of " << tree_count << " trees." << '\n';
                break;
        }
    }
}