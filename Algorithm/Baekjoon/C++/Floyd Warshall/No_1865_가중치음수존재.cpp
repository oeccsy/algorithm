#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n, m, w;
		cin >> n >> m >> w;

		int dist[505][505];

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = (i == j) ? 0 : 10000;

		for (int i = 0; i < m; ++i)
		{
			int s, e, t;
			cin >> s >> e >> t;

			dist[s][e] = min(dist[s][e], t);
			dist[e][s] = min(dist[e][s], t);
		}

		for (int i = 0; i < w; ++i)
		{
			int s, e, t;
			cin >> s >> e >> t;

			dist[s][e] = min(dist[s][e], -t);
		}

		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		bool is_possible = false;

		for (int i = 1; i <= n; ++i)
		{
			if (dist[i][i] < 0)
			{
				is_possible = true;
				break;
			}
		}

		cout << ((is_possible) ? "YES" : "NO") << '\n';
	}
}