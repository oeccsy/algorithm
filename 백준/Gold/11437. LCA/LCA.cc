#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int value = 0;
	int depth = -1;

	Node* parent = nullptr;
	vector<Node*> adj;
};

Node* root = nullptr;
Node* nodes[50005];
Node* parent[50005][20];

void SetParentAndDepth(int n)
{
	queue<Node*> queue;
	root->parent = root;
	root->depth = 0;
	queue.push(root);

	while (!queue.empty())
	{
		Node* cur_node = queue.front();
		queue.pop();

		for (auto& adj_node : cur_node->adj)
		{
			if (adj_node->parent != nullptr) continue;

			adj_node->parent = cur_node;
			adj_node->depth = cur_node->depth + 1;
			queue.push(adj_node);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		parent[i][0] = nodes[i]->parent;
	}

	for (int k = 1; (1 << k) <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			parent[i][k] = parent[parent[i][k - 1]->value][k - 1];
		}
	}
}

Node* LCA(Node* root, Node* node_a, Node* node_b)
{
	if (node_a == root || node_b == root) return root;

	Node* cmp = (node_a->depth < node_b->depth) ? node_a : node_b;
	Node* target = (cmp == node_b) ? node_a : node_b;

	for (int k = 19; k >= 0; --k)
	{
		if (parent[target->value][k] == nullptr) continue;
		if (parent[target->value][k]->depth < cmp->depth) continue;

		target = parent[target->value][k];
	}

	if (cmp == node_a) node_b = target;
	if (cmp == node_b) node_a = target;

	if (node_a == node_b) return node_a;

	for (int k = 19; k >= 0; --k)
	{
		Node* node_a_parent = parent[node_a->value][k];
		Node* node_b_parent = parent[node_b->value][k];
		
		if (node_a_parent == nullptr) continue;
		if (node_b_parent == nullptr) continue;

		if (node_a_parent != node_b_parent)
		{
			node_a = node_a_parent;
			node_b = node_b_parent;
		}
	}

	return node_a->parent;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		nodes[i] = new Node();
		nodes[i]->value = i;
	}

	root = nodes[1];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		Node* u_node = nodes[u];
		Node* v_node = nodes[v];

		u_node->adj.push_back(v_node);
		v_node->adj.push_back(u_node);
	}

	SetParentAndDepth(n);

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		Node* lca = LCA(root, nodes[u], nodes[v]);
		cout << lca->value << '\n';
	}
}