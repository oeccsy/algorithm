#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n, m;

char maze[100][100];
// 0 : 갈 수 없는 칸
// 1 : 갈 수 있는 칸
// 2 : 확인 완료된 갈 수 있는 칸

int dist[100][100];

queue<pair<int, int>> check_target;

void BFS(pair<int, int> start_pos)
{
    check_target.push(start_pos);
    maze[start_pos.first][start_pos.second] = '2';
    dist[start_pos.first][start_pos.second] = 1;
    
    while(!check_target.empty())
    {
        int row = check_target.front().first;
        int col = check_target.front().second;

        int cur_dist = dist[row][col];
        
        check_target.pop();

        if(row + 1 < n && maze[row+1][col] == '1')
        {
            maze[row+1][col] = '2';
            dist[row+1][col] = cur_dist + 1;

            check_target.push({row+1, col});
        }
        if(row - 1 >= 0 && maze[row-1][col] == '1')
        {
            maze[row-1][col] = '2';
            dist[row-1][col] = cur_dist + 1;
            
            check_target.push({row-1, col});
        }
        if(col + 1 < m && maze[row][col+1] == '1')
        {
            maze[row][col+1] = '2';
            dist[row][col+1] = cur_dist + 1;

            check_target.push({row, col+1});
        }
        if(col - 1 >= 0 && maze[row][col-1] == '1')
        {
            maze[row][col-1] = '2';
            dist[row][col-1] = cur_dist + 1;

            check_target.push({row, col-1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char input;
            cin >> input;
            maze[i][j] = input;
        }
    }

    BFS({0,0});

    cout << dist[n-1][m-1];
}