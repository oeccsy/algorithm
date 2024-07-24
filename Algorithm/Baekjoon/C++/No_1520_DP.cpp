#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int map[505][505];
int d[505][505]; // m-1,n-1 까지 가는 방법의 수

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int m, n;

int dfs(int r, int c)
{
  if (d[r][c] != -1) return d[r][c];

  d[r][c] = 0;

  for (int i = 0; i < 4; i++)
  {
    int next_r = r + dy[i];
    int next_c = c + dx[i];

    if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n) continue;
    if (map[r][c] <= map[next_r][next_c]) continue;

    if (d[next_r][next_c] == -1) d[next_r][next_c] = dfs(next_r, next_c);

    d[r][c] += d[next_r][next_c];
  }

  return d[r][c];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m >> n;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
      d[i][j] = -1;
    }
  }

  d[m - 1][n - 1] = 1;
  cout << dfs(0, 0);
}