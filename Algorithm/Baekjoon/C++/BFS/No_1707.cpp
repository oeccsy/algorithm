#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    int mark; // 0 : not marked yet, 1 or 2 : marked
    vector<Node*> adj;
};

vector<Node*> nodes;

bool check_with_bfs(Node* root)
{
    root->mark = 1;
    queue<Node*> queue;
    queue.push(root);
    
    while(!queue.empty())
    {
        Node* cur_node = queue.front();
        queue.pop();
        
        for(auto it=cur_node->adj.begin(); it!=cur_node->adj.end(); it++)
        {
            Node* adj_node = *it;

            if(adj_node->mark==0)
            {
                adj_node->mark = cur_node->mark==2 ? 1 : 2;
                queue.push(adj_node);
            }
            else if(adj_node->mark==cur_node->mark)
            {
                return false;
            }
        }
    }
    
    return true;
}

void reset_mark()
{
    for(auto& node : nodes)
    {
        node->mark = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    
    for(int i=0; i<k; i++)
    {
        int v, e;
        cin >> v >> e;
        
        nodes.clear();
        for(int j=0; j<=v; j++)
        {
            Node* new_node = new Node();
            new_node->data = j;
            nodes.push_back(new_node);
        }
        
        for(int j=0; j<e; j++)
        {
            int input_u, input_v;
            cin >> input_u >> input_v;
            
            nodes[input_u]->adj.push_back(nodes[input_v]);
            nodes[input_v]->adj.push_back(nodes[input_u]);
        }
        
        bool check_result = true;
        
        for(auto node : nodes)
        {
            if(node->data == 0) continue;
            if(node->mark != 0) continue;
            
            check_result = check_with_bfs(node);
            if(check_result==false) break;
        }
        
        if(check_result==true)
            cout << "YES" << '\n';
        else
            cout << "NO" <<'\n';
    }
}