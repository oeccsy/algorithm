#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    vector<Node*> adj;
    bool is_visit;
    
    int score;
    int depth;
};

Node nodes[55];

void bfs(int root_index)
{
    Node* root = &nodes[root_index];
    root->is_visit = true;
    
    queue<Node*> queue;
    queue.push(root);
    
    while(!queue.empty())
    {
        Node* cur_node = queue.front();
        queue.pop();
        
        for(auto it=cur_node->adj.begin(); it!=cur_node->adj.end(); it++)
        {
            Node* adj_node = *it;
            if(adj_node->is_visit) continue;

            adj_node->depth = cur_node->depth + 1;
            root->score = max(root->score, adj_node->depth);
            
            adj_node->is_visit = true;
            queue.push(adj_node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    while(true)
    {
        int a, b;
        cin >> a >> b;
        if(a==-1 && b==-1) break;
        
        nodes[a].adj.push_back(&nodes[b]);
        nodes[b].adj.push_back(&nodes[a]);
    }
    
    for(int i=1; i<=n; i++)
    {
        for(auto& node : nodes)
        {
            node.is_visit = false;
            node.depth = 0;
        }
        
        bfs(i);
    }
    
    vector<int> candidate;
    int min_score = 100;
    
    for(int i=1; i<=n; i++)
    {
        if(nodes[i].score < min_score)
        {
            candidate.clear();
            candidate.push_back(i);
            
            min_score = nodes[i].score;
        }
        else if(nodes[i].score == min_score)
        {
            candidate.push_back(i);
        }
    }
    
    cout << min_score << " " << candidate.size() << '\n';
    for(auto num : candidate) cout << num << " ";
}