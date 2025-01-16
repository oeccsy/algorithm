#include <iostream>

using namespace std;

int board[9][9];

bool is_possible(int r, int c, int num)
{
    for(int i=0; i<9; i++)
    {
        if(board[i][c] == num) return false;
        if(board[r][i] == num) return false;
    }

    int block_r = (r / 3) * 3;
    int block_c = (c / 3) * 3;

    for(int i=block_r; i<block_r+3; i++)
    {
        for(int j=block_c; j<block_c+3; j++)
        {
            if(board[i][j] == num) return false;
        }
    }

    return true;
}

void solve(int r, int c)
{
    if(r >= 9)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                cout << board[i][j];
            }
            cout << '\n';
        }

        exit(0);
    }

    int next_r = r + (c + 1) / 9;
    int next_c = (c + 1) % 9;

    if(board[r][c] != 0)
    {
        solve(next_r, next_c);
        return;
    }

    for(int i=1; i<=9; i++)
    {
        if(is_possible(r, c, i))
        {
            board[r][c] = i;
            solve(next_r, next_c);
            board[r][c] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            char input;
            cin >> input;
            board[i][j] = input - '0';   
        }
    }

    solve(0, 0);
}