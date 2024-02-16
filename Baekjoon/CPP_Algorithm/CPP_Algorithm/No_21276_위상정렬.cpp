#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node
{
    string name;
    
    Node* parent;
    vector<Node*> adj;
    vector<Node*> children;
    
    int indegree = 0;
    bool is_visit = false;
};

map<string, Node*> nodes;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string name_input;
        cin >> name_input;

        Node* new_node = new Node();
        new_node->name = name_input;

        nodes.insert(make_pair(name_input, new_node));
    }
    
    cin >> m;
    for(int i=0; i<m; i++)
    {
        string x_input, y_input;
        cin >> x_input >> y_input;

        Node* x = nodes[x_input];
        Node* y = nodes[y_input];
        
        y->adj.push_back(x);
        x->indegree++;
    }

    int k = 0;
    vector<Node*> root_nodes;
    
    for(auto pair : nodes)
    {
        Node* node = pair.second;
        if(node->indegree > 0) continue;

        k++;
        root_nodes.push_back(node);
    }

    cout << k << '\n';

    for(auto root_node : root_nodes)
    {
        cout << root_node->name << ' ';
    }
    cout << '\n';
    
    for(int i=0; i<n; i++) // Todo : 반복문 횟수 조정, break 고려
    {
        for(auto pair : nodes)
        {
            Node* node = pair.second;
            if(node->indegree > 0) continue;
            if(node->is_visit) continue;

            node->is_visit = true;

            for(auto adj_node : node->adj)
            {
                if(adj_node->indegree == 1) node->children.push_back(adj_node);
                adj_node->indegree--;
            }
        }
    }

    for(auto pair : nodes)
    {
        Node* node = pair.second;

        cout << node->name << ' ' << node->children.size() << ' ';
        for(auto child_node : node->children)
        {
            cout << child_node->name << ' ';
        }
        cout << '\n';
    }
}