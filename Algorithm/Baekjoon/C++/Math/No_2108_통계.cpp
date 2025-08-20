#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

struct Node
{
	int count;
	int value;
};

bool cmp(const Node& a, const Node& b)
{
	if (a.count != b.count)
	{
		return a.count > b.count;
	}
	else
	{
		return a.value > b.value;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> values;

	int sum = 0;
	int max_value = -4000;
	int min_value = 4000;

	int value_count[8005];
	memset(value_count, 0, 8005 * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;

		values.push_back(value);

		sum += value;
		max_value = max(max_value, value);
		min_value = min(min_value, value);

		++value_count[value + 4000];
	}

	vector<Node> nodes;

	for (int i = 0; i < 8005; ++i)
	{
		if (value_count[i] == 0) continue;

		Node node;
		node.count = value_count[i];
		node.value = i - 4000;

		nodes.push_back(node);
	}

	sort(values.begin(), values.end());
	sort(nodes.begin(), nodes.end(), cmp);

	int max_count_index = 0;

	for (int i = 0; i + 1 < nodes.size(); ++i)
	{
		if (nodes[i].count > nodes[i + 1].count)
		{
			max_count_index = i;
			break;
		}
		else
		{
			max_count_index = i + 1;
		}
	}

	int mode = (max_count_index == 0) ? nodes[0].value : nodes[max_count_index - 1].value;

	cout << (int)round(((float)sum / n)) << '\n';
	cout << values[n / 2] << '\n';
	cout << mode << '\n';
	cout << max_value - min_value;
}