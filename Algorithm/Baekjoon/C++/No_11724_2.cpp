#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    vector<Node*> adj;
    bool is_visit = false;
};

Node nodes[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 정점 수 n, 간선 수 m

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;

        nodes[u].adj.push_back(&nodes[v]);
        nodes[v].adj.push_back(&nodes[u]);
    }

    int answer = 0;

    for(int i=1; i<=n; i++)
    {
        if(nodes[i].is_visit) continue;
        
        answer++;
        queue<Node*> bfs_queue;
        bfs_queue.push(&nodes[i]);
        nodes[i].is_visit = true;

        while(!bfs_queue.empty())
        {
            Node* cur_node = bfs_queue.front();
            bfs_queue.pop();

            for(auto adj_node : cur_node->adj)
            {
                if(adj_node->is_visit) continue;
                adj_node->is_visit = true;
                bfs_queue.push(adj_node);
            }
        }
    }

    cout << answer;
}