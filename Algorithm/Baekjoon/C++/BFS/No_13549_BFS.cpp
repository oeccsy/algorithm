#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int visit_time[100005];

struct Node
{
	int pos;
	int time;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	if (n == k)
	{
		cout << 0;
		return 0;
	}

	fill(visit_time, visit_time + 100005, 100000);

	queue<Node> queue;
	Node start = { n, 0 };
	visit_time[n] = 0;
	queue.push(start);

	int answer = 100000;

	while (!queue.empty())
	{
		Node cur_node = queue.front();
		queue.pop();

		vector<Node> adj;
		adj.push_back({ cur_node.pos - 1, cur_node.time + 1 });
		adj.push_back({ cur_node.pos + 1, cur_node.time + 1 });
		adj.push_back({ cur_node.pos * 2, cur_node.time });

		for (Node& adj_node : adj)
		{
			if (adj_node.pos < 0 || adj_node.pos > 100000) continue;
			if (visit_time[adj_node.pos] <= adj_node.time) continue;

			if (adj_node.pos == k) answer = min(answer, adj_node.time);

			visit_time[adj_node.pos] = adj_node.time;
			queue.push(adj_node);
		}
	}

	cout << answer;
}