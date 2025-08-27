#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct Node
{
	int num;
	vector<Node*> adj;

	bool is_non_cycle = false;
	int indegree = 0;
	int dist_to_cycle = -1;
};

Node* nodes[3005];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		nodes[i] = new Node();
		nodes[i]->num = i;
	}

	for (int i = 0; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;

		nodes[u]->adj.push_back(nodes[v]);
		nodes[v]->adj.push_back(nodes[u]);

		nodes[u]->indegree++;
		nodes[v]->indegree++;
	}

	while (true)
	{
		bool find_non_cycle_node = false;

		for (int i = 1; i <= n; ++i)
		{
			Node* cur_node = nodes[i];

			if (cur_node->indegree >= 2) continue;
			if (cur_node->is_non_cycle) continue;
			
			cur_node->is_non_cycle = true;
			find_non_cycle_node = true;

			for (auto adj_node : cur_node->adj)
			{
				adj_node->indegree--;
			}
		}

		if (find_non_cycle_node == false) break;
	}

	queue<Node*> queue;

	for (int i = 1; i <= n; ++i)
	{
		if (nodes[i]->is_non_cycle) continue;
		
		nodes[i]->dist_to_cycle = 0;
		queue.push(nodes[i]);
	}

	while (!queue.empty())
	{
		Node* cur_node = queue.front();
		queue.pop();

		for (auto adj_node : cur_node->adj)
		{
			if (adj_node->dist_to_cycle != -1) continue;

			adj_node->dist_to_cycle = cur_node->dist_to_cycle + 1;
			queue.push(adj_node);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << nodes[i]->dist_to_cycle << " ";
	}
}