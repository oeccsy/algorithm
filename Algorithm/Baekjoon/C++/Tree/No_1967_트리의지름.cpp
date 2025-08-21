#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Node;
struct Edge;

struct Node
{
	int id = 0;
	vector<Edge*> adj;
};

struct Edge
{
	Node* src = nullptr;
	Node* dest = nullptr;
	int dist = 0;
};

Node* nodes[10005];

Node* max_dist_node = nullptr;
int max_dist = 0;

void bfs(Node* start)
{
	bool is_visit[10005];
	int dist[10005];
	memset(is_visit, false, 10005 * sizeof(bool));
	memset(dist, 0, 10005 * sizeof(int));

	queue<Node*> queue;
	is_visit[start->id] = true;
	queue.push(start);

	while (!queue.empty())
	{
		Node* cur_node = queue.front();
		queue.pop();

		for (auto edge : cur_node->adj)
		{
			Node* adj_node = edge->dest;
			if (is_visit[adj_node->id]) continue;
			is_visit[adj_node->id] = true;

			dist[adj_node->id] = dist[cur_node->id] + edge->dist;

			if (max_dist < dist[adj_node->id])
			{
				max_dist_node = adj_node;
				max_dist = dist[adj_node->id];
			}

			queue.push(adj_node);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		nodes[i] = new Node();
		nodes[i]->id = i;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		int parent, child, dist;
		cin >> parent >> child >> dist;

		Edge* pc_edge = new Edge();
		pc_edge->src = nodes[parent];
		pc_edge->dest = nodes[child];
		pc_edge->dist = dist;

		Edge* cp_edge = new Edge();
		cp_edge->src = nodes[child];
		cp_edge->dest = nodes[parent];
		cp_edge->dist = dist;

		nodes[parent]->adj.push_back(pc_edge);
		nodes[child]->adj.push_back(cp_edge);
	}

	bfs(nodes[1]);
	bfs(max_dist_node);

	cout << max_dist;
}