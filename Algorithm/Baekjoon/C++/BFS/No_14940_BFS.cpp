#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node
{
	int row;
	int col;

	int value;

	int dist = -1;
	bool is_visit = false;
};

Node* map[1005][1005];

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	Node* start = nullptr;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			Node* new_node = new Node();
			new_node->row = i;
			new_node->col = j;
			cin >> new_node->value;

			map[i][j] = new_node;

			if (new_node->value == 2) start = new_node;
		}
	}

	queue<Node*> queue;
	start->is_visit = true;
	start->dist = 0;
	queue.push(start);

	while (!queue.empty())
	{
		Node* cur_node = queue.front();
		queue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int next_row = cur_node->row + dr[i];
			int next_col = cur_node->col + dc[i];

			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;

			Node* next_node = map[next_row][next_col];

			if (next_node->is_visit) continue;
			if (next_node->value == 0) continue;

			next_node->is_visit = true;
			next_node->dist = cur_node->dist + 1;

			queue.push(next_node);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			Node* node = map[i][j];

			if (node->value == 0)
			{
				cout << node->value << " ";
			}
			else
			{
				cout << node->dist << " ";
			}
		}

		cout << '\n';
	}
}