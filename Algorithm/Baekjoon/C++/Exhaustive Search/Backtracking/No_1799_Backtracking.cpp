#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int board[11][11]; // 1보다 작으면 놓을 수 없다.
int n;

stack<pair<int,int>> white_history;
stack<pair<int,int>> black_history;
int dr[4] = {1, 1, -1, -1};
int dc[4] = {1, -1, 1, -1};

int max_white = 0;
int max_black = 0;

void add_bishop_ref(int r, int c)
{
    board[r][c]--;
    
    for(int i=0; i<4; i++)
    {
        int cur_r = r;
        int cur_c = c;
        int cur_dr = dr[i];
        int cur_dc = dc[i];

        while(true)
        {
            cur_r += cur_dr;
            cur_c += cur_dc;
        
            if(cur_r < 0 || cur_c < 0 || cur_r >= n || cur_c >= n) break;

            board[cur_r][cur_c]--;
        }
    }
}

void remove_bishop_ref(int r, int c)
{
    board[r][c]++;
    
    for(int i=0; i<4; i++)
    {
        int cur_r = r;
        int cur_c = c;
        int cur_dr = dr[i];
        int cur_dc = dc[i];

        while(true)
        {
            cur_r += cur_dr;
            cur_c += cur_dc;
        
            if(cur_r < 0 || cur_c < 0 || cur_r >= n || cur_c >= n) break;

            board[cur_r][cur_c]++;
        }
    }
}

void check_white(int count)
{
    for(int i=0; i<n; i++)
    {
        for(int j=(i % 2); j<n; j+=2)
        {
            if(board[i][j] < 1) continue;
            if(!white_history.empty())
            {
                int prev_index = n * white_history.top().first + white_history.top().second;
                int cur_index = n * i + j;

                if(cur_index <= prev_index) continue;
            }

            white_history.push({i,j});
            add_bishop_ref(i, j);

            max_white = max(max_white, count);
            check_white(count+1);
            
            white_history.pop();
            remove_bishop_ref(i, j);
        }
    }
}

void check_black(int count)
{
    for(int i=0; i<n; i++)
    {
        for(int j=((i+1) % 2); j<n; j+=2)
        {
            if(board[i][j] < 1) continue;
            if(!black_history.empty())
            {
                int prev_index = n * black_history.top().first + black_history.top().second;
                int cur_index = n * i + j;

                if(cur_index <= prev_index) continue;
            }

            black_history.push({i,j});
            add_bishop_ref(i, j);

            max_black = max(max_black, count);
            check_black(count+1);
            
            black_history.pop();
            remove_bishop_ref(i, j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 체스 비숍은 대각선 방향으로 이동
    // 비숍을 놓을 수 없는 칸 존재
    // 체스 크기 n일때 보드는 n x n (n <= 10)
    // 비숍 놓을 수 있음 1, 비숍놓을 수 없음 0
    
    // 서로를 잡을 수 없도록 비숍을 놓는 수의 최댓값
    // *검정칸 흰색칸은 서로 영향을 주지 않음 -> 나눠서 생각하기

    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> board[i][j];
        }
    }

    check_white(1);
    check_black(1);

    cout << max_white + max_black;
}