#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct Node
{
    int indegree = 0;
    int outdegree = 0;
    bool is_visit = false;
    vector<Node*> adj;
};

unordered_map<int, Node*> nodes;

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4,0);
    vector<Node*> start_nodes;
    
    for(auto edge : edges)
    {
        int src = edge[0];
        int dest = edge[1];
        
        if(nodes.find(src) == nodes.end()) nodes[src] = new Node();
        if(nodes.find(dest) == nodes.end()) nodes[dest] = new Node();
        
        nodes[src]->adj.push_back(nodes[dest]);
        nodes[src]->outdegree++;
        nodes[dest]->indegree++;
    }
    
    for(auto& pair : nodes)
    {
        int cur_node_num = pair.first;
        Node* cur_node = pair.second;
        
        if(cur_node->indegree == 0 && cur_node->outdegree >= 2)
        {
            answer[0] = cur_node_num;
            start_nodes = cur_node->adj;
            break;
        }
    }

    for(auto& start_node : start_nodes)
    {
        stack<Node*> dfs_stack;
        start_node->is_visit = true;
        dfs_stack.push(start_node);
        
        int v_count = 0;
        int e_count = 0;
        
        while(!dfs_stack.empty())
        {
            Node* dfs_node = dfs_stack.top();
            dfs_stack.pop();
            v_count++;
            
            for(auto& adj_node : dfs_node->adj)
            {
                e_count++;
                if(adj_node->is_visit) continue;
                
                adj_node->is_visit = true;
                dfs_stack.push(adj_node);
            }
        }
        
        if(v_count == e_count) answer[1]++;
        if(v_count - 1 == e_count) answer[2]++;
        if(v_count + 1 == e_count) answer[3]++;
    }

    return answer;
}