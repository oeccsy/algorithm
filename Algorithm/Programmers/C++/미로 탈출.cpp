#include <string>
#include <vector>
#include <queue>

using namespace std;

bool is_visit[105][105];
int dist[105][105];

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void bfs(vector<string>& maps, pair<int, int> start)
{
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            is_visit[i][j] = false;
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> queue;

    is_visit[start.first][start.second] = true;
    dist[start.first][start.second] = 0;

    queue.push(start);

    while (!queue.empty())
    {
        pair<int, int> cur_pos = queue.front();
        queue.pop();

        int cur_dist = dist[cur_pos.first][cur_pos.second];

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next_pos;
            next_pos.first = cur_pos.first + dr[i];
            next_pos.second = cur_pos.second + dc[i];

            if (next_pos.first < 0 || next_pos.first >= maps.size() || next_pos.second < 0 || next_pos.second >= maps[0].size()) continue;
            if (is_visit[next_pos.first][next_pos.second]) continue;
            if (maps[next_pos.first][next_pos.second] == 'X') continue;

            is_visit[next_pos.first][next_pos.second] = true;
            dist[next_pos.first][next_pos.second] = cur_dist + 1;

            queue.push(next_pos);
        }
    }
}

int solution(vector<string> maps)
{
    pair<int, int> l_pos = { -1, -1 };
    pair<int, int> s_pos = { -1, -1 };
    pair<int, int> e_pos = { -1, -1 };

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'L')
            {
                l_pos = { i, j };
            }
            else if (maps[i][j] == 'S')
            {
                s_pos = { i, j };
            }
            else if (maps[i][j] == 'E')
            {
                e_pos = { i, j };
            }
        }
    }

    bfs(maps, s_pos);
    int s_to_l_dist = dist[l_pos.first][l_pos.second];
    if (s_to_l_dist == -1) return -1;

    bfs(maps, l_pos);
    int l_to_e_dist = dist[e_pos.first][e_pos.second];
    if (l_to_e_dist == -1) return -1;

    return s_to_l_dist + l_to_e_dist;
}