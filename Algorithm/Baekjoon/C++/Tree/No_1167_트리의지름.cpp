#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Node;
struct Edge;

struct Node
{
	int id;
	vector<Edge*> adj;
};

struct Edge
{
	Node* src = nullptr;
	Node* dest = nullptr;
	int dist = 0;
};

Node* nodes[100005];
Node* far = nullptr;
int max_dist = 0;

void bfs(Node* start)
{
	bool is_visit[100005];
	int dist[100005];
	fill(is_visit, is_visit + 100005, false);
	fill(dist, dist + 100005, 0);

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
				max_dist = dist[adj_node->id];
				far = adj_node;
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

	int v;
	cin >> v;

	for (int i = 1; i <= v; ++i)
	{
		nodes[i] = new Node();
		nodes[i]->id = i;
	}

	for (int i = 0; i < v; ++i)
	{
		int src;
		cin >> src;

		while (true)
		{
			int dest;
			cin >> dest;
			if (dest == -1) break;

			int dist;
			cin >> dist;

			nodes[src]->adj.push_back(new Edge({ nodes[src], nodes[dest], dist }));
		}
	}

	bfs(nodes[1]);
	bfs(far);

	cout << max_dist;
}