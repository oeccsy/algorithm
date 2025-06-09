#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int row;
    int col;

    int weight;

    int min_dist;
};

Node* maze[101][101];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 미로 N*M 크기
    // 미로는 빈방 또는 벽
    // 이동할 수 있는 방 상하좌우, 미로 밖 이동 불가
    // 1,1 에 있는 운영진이 N,M으로 이동하려면 벽을 "최소" 몇 개 부숴야 하는지 구하시오
    // N,M <= 100
    // 0은 빈 방, 1은 벽

    int m, n;
    cin >> m >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char input;
            cin >> input;

            Node* new_node = new Node();
            new_node->row = i;
            new_node->col = j;
            new_node->weight = input - '0';
            new_node->min_dist = 10000000;

            maze[i][j] = new_node;
        }
    }

    priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
    maze[1][1]->min_dist = 0;
    pq.push({0, maze[1][1]});

    while(!pq.empty())
    {
        int min_dist = pq.top().first;
        Node* cur_node = pq.top().second;
        pq.pop();

        if(min_dist != cur_node->min_dist) continue;

        for(int i=0; i<4; i++)
        {
            int next_row = cur_node->row + dy[i];
            int next_col = cur_node->col + dx[i];

            if(next_row <= 0 || next_row > n) continue;
            if(next_col <= 0 || next_col > m) continue;
            
            Node* adj_node = maze[next_row][next_col];
            int new_dist = cur_node->min_dist + adj_node->weight;
            
            if(new_dist < adj_node->min_dist)
            {
                adj_node->min_dist = new_dist;
                pq.push({new_dist, adj_node});
            }
        }
    }

    cout << maze[n][m]->min_dist;
}