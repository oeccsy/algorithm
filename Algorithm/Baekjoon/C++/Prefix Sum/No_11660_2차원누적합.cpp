#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int value;
			cin >> value;

			int prev_row_sum = (i - 1 < 0) ? 0 : sum[i - 1][j];
			int prev_col_sum = (j - 1 < 0) ? 0 : sum[i][j - 1];
			int prev_row_col_sum = (i - 1 < 0 || j - 1 < 0) ? 0 : sum[i - 1][j - 1];

			sum[i][j] = prev_row_sum + prev_col_sum - prev_row_col_sum + value;
		}
	}

	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sum_x1y1 = (x1 - 1 < 0 || y1 - 1 < 0) ? 0 : sum[x1 - 1][y1 - 1];
		int sum_x1y2 = (x1 - 1 < 0) ? 0 : sum[x1 - 1][y2];
		int sum_x2y1 = (y1 - 1 < 0) ? 0 : sum[x2][y1 - 1];

		int result = sum[x2][y2] + sum_x1y1 - sum_x1y2 - sum_x2y1;
		cout << result << '\n';
	}
}