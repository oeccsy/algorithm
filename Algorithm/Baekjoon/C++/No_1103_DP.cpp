#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[55][55];
int d[55][55]; // [i][j] 에서 이동할 수 있는 최대 횟수
bool is_confirm[55][55];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m;

int dfs(int r, int c)
{
  if (board[r][c] == -1) return 0;
  if (d[r][c] != -1)
  {
    if(is_confirm[r][c])
    {
      return d[r][c];
    }
    else
    {
      return -1;
    }
  }

  d[r][c] = 1;

  for (int i = 0; i < 4; i++)
  {
    int next_r = r + dy[i] * board[r][c];
    int next_c = c + dx[i] * board[r][c];

    if (next_r >= n || next_r < 0 || next_c >= m || next_c < 0) continue;
    if (board[next_r][next_c] == -1) continue;

    d[next_r][next_c] = dfs(next_r, next_c);
    if (d[next_r][next_c] == -1) return -1;
    
    d[r][c] = max(d[r][c], 1 + d[next_r][next_c]);
  }

  is_confirm[r][c] = true;
  return d[r][c];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char input;
      cin >> input;

      if (input == 'H')
      {
        board[i][j] = -1;
      }
      else
      {
        board[i][j] = input - '0';
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      d[i][j] = -1;
    }
  }

  cout << dfs(0,0);
}