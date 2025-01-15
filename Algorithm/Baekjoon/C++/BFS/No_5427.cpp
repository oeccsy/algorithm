#include <iostream>
#include <queue>

using namespace std;

int t, w, h;

char building[1002][1002];
int fire_dist[1002][1002];
int player_dist[1002][1002];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> fire;
queue<pair<int, int>> player;

void BFS_Fire()
{
    while (!fire.empty())
    {
        pair<int, int> cur = fire.front();
        fire.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};

            if (next.first < 0 || next.second < 0 || next.first >= h || next.second >= w) continue;
            if (fire_dist[next.first][next.second] > 0) continue;
            if (building[next.first][next.second] == '#' || building[next.first][next.second] == '*') continue;

            fire_dist[next.first][next.second] = fire_dist[cur.first][cur.second] + 1;
            fire.push(next);
        }
    }
}

void BFS_Player()
{
    while (!player.empty())
    {
        pair<int, int> cur = player.front();
        player.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {cur.first + dx[i], cur.second + dy[i]};

            if (next.first < 0 || next.second < 0 || next.first >= h || next.second >= w)
            {
                cout << player_dist[cur.first][cur.second] + 1 << '\n';
                while(!player.empty()) player.pop();
                return;
            }

            if (player_dist[next.first][next.second] > 0 || building[next.first][next.second] != '.') continue;
            if (player_dist[cur.first][cur.second] + 1 >= fire_dist[next.first][next.second] && fire_dist[next.first][next.second] != 0) continue;
            // fire_dist[next.first][next.second] != 0 을 검사하지 않으면 틀린다. 0은 거리가 아닌 아직 불이 번지지 않음을 표시했기 때문.

            player_dist[next.first][next.second] = player_dist[cur.first][cur.second] + 1;
            player.push(next);
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (int repeat = 0; repeat < t; repeat++)
    {
        cin >> w >> h;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char input;
                cin >> input;
                building[i][j] = input;
                fire_dist[i][j] = 0;
                player_dist[i][j] = 0;

                if (input == '*') fire.push({i, j});
                if (input == '@') player.push({i, j});
            }
        }

        BFS_Fire();
        BFS_Player();
    }
}
