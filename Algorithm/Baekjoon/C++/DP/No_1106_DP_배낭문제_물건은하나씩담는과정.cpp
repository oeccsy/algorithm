#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[20][100005]; // i번째 도시까지 고려했을 때 j원으로 얻을 수 있는 최대 고객 수

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int c, n;  // c <= 1000, n <= 20, 목표 c, 도시 수 n
	cin >> c >> n;

	int cost[20];
	int increase[20];

	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i];
		cin >> increase[i];
	}

	for (int i = 0; i < n; ++i) // 마을 순환
	{
		for (int j = 0; j < 100005; ++j) // 돈 순환
		{
			int include_case = (j - cost[i] < 0) ? 0 : d[i][j - cost[i]] + increase[i];
			int exclude_case = (i - 1 < 0) ? 0 : d[i - 1][j];
			int invalid_case = (j - 1 < 0) ? 0 : d[i][j - 1];

			d[i][j] = max({ include_case, exclude_case, invalid_case });
			if (d[i][j] >= c) break;
		}
	}

	for (int j = 0; j < 100005; ++j)
	{
		if (d[n - 1][j] >= c)
		{
			cout << j;
			return 0;
		}
	}
}