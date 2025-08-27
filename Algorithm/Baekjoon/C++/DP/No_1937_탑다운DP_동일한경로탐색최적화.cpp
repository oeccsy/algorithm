#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int forest[505][505];
int max_move = 0;

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int d[505][505]; // i,j에서 시작했을 때 지나는 최대 칸 수

int max_move_count(int row, int col, int n)
{
	if (d[row][col] != -1) return d[row][col];

	int count = 1;

	for (int i = 0; i < 4; ++i)
	{
		int next_row = row + dr[i];
		int next_col = col + dc[i];

		if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;

		if (forest[row][col] < forest[next_row][next_col])
		{
			count = max(count, max_move_count(next_row, next_col, n) + 1);
		}
	}

	d[row][col] = count;

	return count;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> forest[i][j];
			d[i][j] = -1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			max_move = max(max_move, max_move_count(i, j, n));
		}
	}

	cout << max_move;
}