#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int w[16][16];
int d[16][1 << 16];	//d[i][mask] -> 현재 i에 있고 mask 만큼 순회했을 때 까지 비용의 최솟값

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> w[i][j];

	for (int i = 0; i < n; ++i)
		for (int mask = 0; mask < (1 << n); ++mask)
			d[i][mask] = INF;

	d[0][1 << 0] = 0;

	for (int mask = 0; mask < (1 << n); ++mask)
	{
		for (int i = 0; i < n; ++i)
		{
			if (d[i][mask] == INF) continue;

			for (int j = 0; j < n; ++j)
			{
				if (mask & (1 << j)) continue;
				if (w[i][j] == 0) continue;

				int nextMask = mask | (1 << j);
				d[j][nextMask] = min(d[j][nextMask], d[i][mask] + w[i][j]);
			}
		}
	}

	int minWeight = INF;

	for (int i = 1; i < n; ++i)
	{
		if (w[i][0] == 0) continue;
		minWeight = min(minWeight, d[i][(1 << n) - 1] + w[i][0]);
	}

	cout << minWeight;
}