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

Node vertices[1001];
int componentCount = 0;

void BFS(int start)
{
    if(vertices[start].is_visit) return;
    componentCount++;
    
    vertices[start].is_visit = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty())
    {
        Node curNode = vertices[q.front()];
        q.pop();
        for(auto it = curNode.adj.begin(); it!=curNode.adj.end(); ++it)
        {
            if(vertices[*it].is_visit) continue;
            
            vertices[*it].is_visit = true;
            q.push(*it);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        vertices[u].adj.push_back(v);
        vertices[v].adj.push_back(u);
    }
    
    for(int i=1; i<=n; i++)
    {
        BFS(i);
    }
    
    cout << componentCount;
}