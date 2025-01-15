#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int delay = 0;
    int prev_delay = 0;
    int indegree = 0;
    vector<Node*> adj;
    bool is_visit = false;
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

        bool find_w = false;

        while(find_w == false)
        {
            for(int j=1; j<=n; j++)
            {
                Node* cur_node = nodes[j];
                if(cur_node->indegree > 0) continue;
                if(cur_node->is_visit) continue;

                cur_node->is_visit = true;
                
                if(cur_node == nodes[w])
                {
                    find_w = true;
                    cout << cur_node->prev_delay + cur_node->delay << '\n';
                    break;
                }

                for(auto adj_node : cur_node->adj)
                {
                    adj_node->prev_delay = max(adj_node->prev_delay, cur_node->prev_delay + cur_node->delay);
                    adj_node->indegree--;
                }
            }
        }
    }
}