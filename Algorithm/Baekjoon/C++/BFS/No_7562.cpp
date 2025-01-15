#include <iostream>
#include <queue>

using namespace std;

int t, l, start_row, start_col, goal_row, goal_col;

queue<pair<int, int>> check_target;
int board[300][300]; //보드의 해당 위치까지 필요한 움직임 횟수(거리)
// 0 : 시작 위치
// -1 : 확인하지 않은 위치
// k : 확인한 위치

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void BFS(pair<int, int> start, pair<int,int> goal)
{
    check_target.push(start);

    while(!check_target.empty())
    {
        pair<int, int> cur = check_target.front();
        check_target.pop();

        int dist = board[cur.first][cur.second];

        if(cur == goal)
        {
            cout << dist << '\n';
            break;
        }

        for(int d = 0; d < 8; d++)
        {
            pair<int, int> next = {cur.first+dx[d], cur.second+dy[d]};
            if( 0 <= next.first && next.first < l && 0 <= next.second && next.second < l && board[next.first][next.second] == -1)
            {
                board[next.first][next.second] = dist + 1;
                check_target.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> l;
        cin >> start_row >> start_col;
        cin >> goal_row >> goal_col;

        for(int row = 0; row<300; row++)
        {
            for(int col = 0; col<300; col++)
            {
                board[row][col] = -1;
            }
        }

        queue<pair<int,int>> empty;
        check_target.swap(empty);

        board[start_row][start_col] = 0;
        
        BFS({start_row, start_col}, {goal_row, goal_col});
    }
}