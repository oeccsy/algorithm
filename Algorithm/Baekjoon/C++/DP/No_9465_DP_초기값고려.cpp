#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<int> sticker[2];
		vector<int> d[2];	// i, j를 떼어냈을 때 최댓값

		for (int i = 0; i < n; ++i)
		{
			int value;
			cin >> value;
			sticker[0].push_back(value);
			d[0].push_back(0);
		}

		for (int i = 0; i < n; ++i)
		{
			int value;
			cin >> value;
			sticker[1].push_back(value);
			d[1].push_back(0);
		}

		for (int i = 0; i < n; ++i)
		{
			int prev_1_max = (i - 1 < 0) ? 0 : d[1][i - 1];
			int prev_2_max = (i - 2 < 0) ? 0 : d[1][i - 2];

			d[0][i] = max(prev_1_max, prev_2_max) + sticker[0][i];

			prev_1_max = (i - 1 < 0) ? 0 : d[0][i - 1];
			prev_2_max = (i - 2 < 0) ? 0 : d[0][i - 2];

			d[1][i] = max(prev_1_max, prev_2_max) + sticker[1][i];
		}

		cout << max(d[0][n - 1], d[1][n - 1]) << '\n';
	}
}