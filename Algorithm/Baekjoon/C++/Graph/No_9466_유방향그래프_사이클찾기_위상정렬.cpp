#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 어느 프로젝트 팀에도 속하지 않는 학생 수 계산

struct Node
{
	int num;
	std::vector<Node*> adj;

	int indegree = 0;
};

Node* nodes[100005];

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; ++i)
		{
			nodes[i] = new Node();
			nodes[i]->num = i;
		}

		for (int i = 1; i <= n; ++i)
		{
			int selected;
			cin >> selected;

			nodes[i]->adj.push_back(nodes[selected]);
			nodes[selected]->indegree++;
		}

		queue<Node*> search_targets;

		for (int i = 1; i <= n; ++i)
		{
			if (nodes[i]->indegree == 0) search_targets.push(nodes[i]);
		}

		int non_cycle_count = 0;

		while (!search_targets.empty())
		{
			Node* cur_node = search_targets.front();
			search_targets.pop();

			++non_cycle_count;

			for (auto adj_node : cur_node->adj)
			{
				adj_node->indegree--;
				if (adj_node->indegree == 0) search_targets.push(adj_node);
			}
		}

		cout << non_cycle_count << '\n';

		for (int i = 1; i <= n; ++i)
		{
			delete nodes[i];
		}
	}
}