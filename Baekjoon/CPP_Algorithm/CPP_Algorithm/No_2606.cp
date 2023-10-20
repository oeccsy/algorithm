#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int number;
    vector<int> adj;
    bool is_visit;
};

Node nodes[101];
int result = 0;

void BFS(int start_node_num)
{
    nodes[start_node_num].is_visit = true;
    queue<int> next_node_nums;
    next_node_nums.push(start_node_num);
    
    while(!next_node_nums.empty())
    {
        Node curNode = nodes[next_node_nums.front()];
        next_node_nums.pop();
      
        for(auto it=curNode.adj.begin(); it != curNode.adj.end(); ++it)
        {
            if(nodes[*it].is_visit) continue;
            
            nodes[*it].is_visit = true;
            next_node_nums.push(*it);
            result++;
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int node_count;
    int edge_count;
    cin >> node_count;
    cin >> edge_count;
    
    for(int i=0; i<edge_count; i++)
    {
        int u,v;
        cin >> u >> v;
        nodes[u].adj.push_back(v);
        nodes[v].adj.push_back(u);
    }
    
    BFS(1);
    
    cout<<result;
}