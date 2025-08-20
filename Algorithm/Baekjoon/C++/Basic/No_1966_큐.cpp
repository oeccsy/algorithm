#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	int value;
	int index;
};

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		queue<Node> queue;
		priority_queue<int> values;

		for (int i = 0; i < n; ++i)
		{
			Node node;
			cin >> node.value;
			node.index = i;

			queue.push(node);
			values.push(node.value);
		}

		for (int i = 1; i <= n; ++i)
		{
			int target_value = values.top();
			values.pop();

			Node selected;

			while (true)
			{
				selected = queue.front();
				queue.pop();

				if (selected.value == target_value) break;

				queue.push(selected);
			}

			if (selected.index == m) cout << i << '\n';
		}
	}
}