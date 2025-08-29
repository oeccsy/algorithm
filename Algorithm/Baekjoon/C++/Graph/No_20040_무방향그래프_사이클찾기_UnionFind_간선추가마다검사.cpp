#include <iostream>

using namespace std;

int parent[500005];

void Union(int u, int v);
int Find(int u);

void Union(int u, int v)
{
	int u_root = Find(u);
	int v_root = Find(v);

	parent[v_root] = u_root;
}

int Find(int u)
{
	if (parent[u] == u)
	{
		return u;
	}
	else
	{
		parent[u] = Find(parent[u]);
		return parent[u];
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;

		if (Find(u) == Find(v))
		{
			cout << i;
			return 0;
		}
		else
		{
			Union(u, v);
		}
	}

	cout << 0;
	return 0;
}