#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;

	int n;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;

		if (x > 0)
		{
			pq.push(x);
		}
		else if (x == 0)
		{
			int min = (pq.empty()) ? 0 : pq.top();
			cout << min << '\n';

			if (!pq.empty()) pq.pop();
		}
	}
}