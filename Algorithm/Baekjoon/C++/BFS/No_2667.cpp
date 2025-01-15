#include <iostream>
#include <queue>
#include <algorithm> 

using namespace std;

int n;
int map[25][25];
bool visit[25][25];

queue<pair<int,int>> check_target;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int town_size[625];
int town_count = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            char input;
            cin >> input;
            map[i][j] = input - '0';
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j] != 0 && visit[i][j] == false)
            {
                town_count++;
                
                map[i][j] = town_count;
                visit[i][j] = true;
                town_size[town_count]++;
                check_target.push({i,j});

                while(!check_target.empty())
                {
                    pair<int,int> cur = check_target.front();
                    check_target.pop();

                    for(int idx=0; idx<4; idx++)
                    {
                        pair<int,int> next = {cur.first + dx[idx], cur.second + dy[idx]};

                        if(next.first < 0 || next.second < 0 || next.first >= n || next.second >= n) continue;
                        if(map[next.first][next.second] == 0) continue;
                        if(visit[next.first][next.second]) continue;

                        map[next.first][next.second] = town_count;
                        visit[next.first][next.second] = true;
                        town_size[town_count]++;
                        check_target.push(next);
                    }
                }
            }
        }
    }

    sort(town_size, town_size+(n*n));
    cout << town_count << '\n';
    for(int size : town_size)
    {
        if(size == 0) continue;
        cout << size << "\n";
    }
}