#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int parent;
    vector<int> adj;
};

Node nodes[100001];

void set_parent_with_bfs(int start_index)
{
    queue<int> q;
    
    nodes[start_index].parent = 1;
    q.push(start_index);
    
    while(!q.empty())
    {
        int curNodeIndex = q.front();
        q.pop();
        
        Node curNode = nodes[curNodeIndex];
        
        for(auto it=curNode.adj.begin(); it!=curNode.adj.end(); ++it)
        {
            if(nodes[*it].parent != 0) continue;
         
            nodes[*it].parent = curNodeIndex;
            q.push(*it);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        
        nodes[u].adj.push_back(v);
        nodes[v].adj.push_back(u);
    }
    
    set_parent_with_bfs(1);
    
    for(int i=2; i<=n; i++)
    {
        cout << nodes[i].parent << '\n';
    }
}