#include <iostream>
#include <algorithm>

using namespace std;

int triangle[505][505];
int d[505][505];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> triangle[i][j];
		}

		for (int j = 0; j <= i; ++j)
		{
			int left_parent = (i - 1 < 0 || j - 1 < 0) ? 0 : d[i - 1][j - 1];
			int right_parent = (i - 1 < 0) ? 0 : d[i - 1][j];
			d[i][j] = max(left_parent, right_parent) + triangle[i][j];
		}
	}

	int max_sum = 0;

	for (int j = 0; j < n; ++j)
	{
		if (d[n - 1][j] > max_sum) max_sum = d[n - 1][j];
	}

	cout << max_sum;
}