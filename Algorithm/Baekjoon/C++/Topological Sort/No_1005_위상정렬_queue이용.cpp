#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    int delay = 0;
    int prev_delay = 0;
    int indegree = 0;
    vector<Node*> adj;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 특정 건물을 가장 빨리 지을 때까지 걸리는 최소시간
    // 각 노드는 건설 조건 도달 시간 저장

    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        int n, k;
        cin >> n >> k;

        Node* nodes[1005];

        for(int j=1; j<=n; j++)
        {
            nodes[j] = new Node();
            cin >> nodes[j]->delay;
        }

        for(int j=0; j<k; j++)
        {
            int x, y;
            cin >> x >> y;

            nodes[x]->adj.push_back(nodes[y]);
            nodes[y]->indegree++;
        }

        int w;
        cin >> w;

        queue<Node*> leaf_nodes;

        for(int j=1; j<=n; j++)
        {
            if(nodes[j]->indegree > 0) continue;
            leaf_nodes.push(nodes[j]);
        }

        while(!leaf_nodes.empty())
        {
            Node* cur_node = leaf_nodes.front();
            leaf_nodes.pop();

            if(cur_node == nodes[w])
            {
                cout << cur_node->prev_delay + cur_node->delay << '\n';
                break;
            }

            for(auto adj_node : cur_node->adj)
            {
                adj_node->prev_delay = max(adj_node->prev_delay, cur_node->prev_delay + cur_node->delay);
                adj_node->indegree--;

                if(adj_node->indegree == 0) leaf_nodes.push(adj_node);
            }    
        }
    }
}