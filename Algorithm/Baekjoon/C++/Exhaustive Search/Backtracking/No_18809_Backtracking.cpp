#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, g, r;

int map[55][55];
bool is_used[55][55];

vector<pair<int,int>> green_area;
vector<pair<int,int>> red_area;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int answer = 0;

int flower_count()
{
    int flower_count = 0;
    int depth[55][55];
    char status[55][55];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            depth[i][j] = 0;
            status[i][j] = 'X';
        }
    }

    queue<pair<int,int>> bfs_queue;
    for(int i=0; i<g; i++)
    {
        bfs_queue.push(green_area[i]);
        int r = green_area[i].first;
        int c = green_area[i].second;

        depth[r][c] = 1;
        status[r][c] = 'G';
    }
    for(int i=0; i<r; i++)
    {
        bfs_queue.push(red_area[i]);
        int r = red_area[i].first;
        int c = red_area[i].second;

        depth[r][c] = 1;
        status[r][c] = 'R';
    }

    while(!bfs_queue.empty())
    {
        int cur_r = bfs_queue.front().first;
        int cur_c = bfs_queue.front().second;
        bfs_queue.pop();

        int cur_depth = depth[cur_r][cur_c];
        char cur_status = status[cur_r][cur_c];

        if(cur_status == 'F') continue;

        for(int i=0; i<4; i++)
        {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];

            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(map[nr][nc] == 0) continue;
            
            if(depth[nr][nc] == 0)
            {
                bfs_queue.push({nr, nc});
                depth[nr][nc] = cur_depth + 1;
                status[nr][nc] = cur_status;
            }
            else if((depth[nr][nc] == cur_depth + 1) && (status[nr][nc] + cur_status == 'G' + 'R'))
            {
                flower_count++;
                status[nr][nc] = 'F';
            }
        }
    }

    return flower_count;
}

void select(int green_count, int red_count)
{
    if(green_count == g && red_count == r)
    {
        answer = max(answer, flower_count());
        return;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(is_used[i][j]) continue;
            if(map[i][j] != 2) continue;

            vector<pair<int,int>>& target_area = (green_area.size() < g) ? green_area : red_area;
            if(!target_area.empty())
            {
                int prev_index = m * target_area.back().first + target_area.back().second;
                int cur_index = m * i + j;

                if(cur_index <= prev_index) continue;
            }

            target_area.push_back({i, j});
            is_used[i][j] = true;
            select(green_area.size(), red_area.size());
            is_used[i][j] = false;
            target_area.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 꽃을 정원에 피우려고 한다.
    // 정원은 땅과 호수로 이뤄짐
    // 초록색 배양액, 빨간색 배양액 이용하여 꽃 피움
    // 배양액은 인접한 땅으로 퍼진다.
    // 하얀 땅 배양액 뿌릴 수 없음, 황토 땅 배양액 뿌릴 수 있음, 하늘색 호수
    // 빨간 배양액, 초록 배양액 동시에 도달하면 꽃이 피어남 꽃이 피어나면 인접한 곳으로 배양액 안퍼짐
    

    // 모든 배양액 사용해야함
    // 배양액 서로 다른 곳에 뿌려져야 함
    // 정원의 행/열 N/M
    // 초록 배양액 수 G
    // 빨간 배양액 수 R
    // 0 = 호수, 1 = 배양액 뿌리기 불가, 2 = 배양액 뿌리기 가능

    // 뿌릴 땅 선정 -> 백트래킹
    // 결과 확인 -> bfs
    // 최댓값 기록

    
    cin >> n >> m >> g >> r;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    select(green_area.size(), red_area.size());

    cout << answer;
}