#include <string>
#include <vector>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

struct Node
{
    int node_num;
    int indegree = 0;
    int outdegree = 0;
    int topology = -1; // 0 : donut, 1 : stick, 8 : eight
    bool is_visit = false;
    vector<Node*> adj;
    
    Node(int n)
    {
        node_num = n;
    }
};

map<int, Node*> nodes;

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer;
    
    for(auto edge : edges)
    {
        int src = edge[0];
        int dest = edge[1];
        
        if(nodes.find(src) == nodes.end()) nodes[src] = new Node(src);
        if(nodes.find(dest) == nodes.end()) nodes[dest] = new Node(dest);
        
        nodes[src]->outdegree++;
        nodes[src]->adj.push_back(nodes[dest]);
        nodes[dest]->indegree++;
    }
    
    int indie_node_num;
    int donut_count = 0;
    int stick_count = 0;
    int eight_count = 0;
    
    for(auto pair : nodes)
    {
        int cur_node_num = pair.first;
        Node* cur_node = pair.second;
        
        if(cur_node->topology != -1) continue;
        
        if(cur_node->indegree == 0 && cur_node->outdegree >= 2)
        {
            indie_node_num = cur_node_num;
            cur_node->is_visit = true;
            
            cout << "end : is indie" << endl;
            continue;
        }
        
        stack<Node*> dfs_stack;
        cur_node->is_visit = true;
        dfs_stack.push(cur_node);
        
        vector<Node*> visit_history;
        visit_history.push_back(cur_node);
        
        bool has_cycle = false;
        bool has_center = false;
        int topology = -1;
        
        while(!dfs_stack.empty())
        {
            Node* prev_node = dfs_stack.top();
            dfs_stack.pop();
            
            for(auto adj_node : prev_node->adj)
            {    
                if(adj_node->is_visit) has_cycle = true;
                if(adj_node->outdegree == 2) has_center = true;
                if(adj_node->topology != -1) topology = adj_node->topology;
                if(adj_node->is_visit) continue;
                
                adj_node->is_visit = true;
                dfs_stack.push(adj_node);
                
                visit_history.push_back(adj_node);
            }
        }
        
        if(topology == -1)
        {
            if(has_cycle && has_center)
            {
                topology = 8;
                eight_count++;
            }
            else if(has_cycle)
            {
                topology = 0;
                donut_count++;
            }
            else
            {
                topology = 1;
                stick_count++;
            }
        }
        
        for(auto node : visit_history)
        {
            node->topology=topology;
        }
    }
    
    answer.push_back(indie_node_num);
    answer.push_back(donut_count);
    answer.push_back(stick_count);
    answer.push_back(eight_count);
    
    return answer;
}