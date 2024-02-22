#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int index;
    
    int dist = 0;
    vector<Node*> adj;
    bool is_checked = false;
};

Node* nodes[20005];

int solution(int n, vector<vector<int>> edge) {
    int max_dist = 0;
    int answer = 0;
    
    for(int i=1; i<=n; i++)
    {
        nodes[i] = new Node();
        nodes[i]->index = i;
    }
    
    for(auto e : edge)
    {
        Node* node_0 = nodes[e[0]];
        Node* node_1 = nodes[e[1]];
        
        node_0->adj.push_back(node_1);
        node_1->adj.push_back(node_0);
    }
    
    queue<Node*> q;
    nodes[1]->is_checked = true;
    q.push(nodes[1]);
    
    while(!q.empty())
    {
        Node* cur_node = q.front();
        q.pop();
        
        for(auto adj_node : cur_node->adj)
        {
            if(adj_node->is_checked) continue;
            
            adj_node->dist = cur_node->dist+1;
            
            if(max_dist < adj_node->dist)
            {
                max_dist = adj_node->dist;
                answer = 0;
            }
            if(max_dist == adj_node->dist) answer++;
            
            adj_node->is_checked = true;
            q.push(adj_node);
        }
    }
    
    return answer;
}