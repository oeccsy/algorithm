#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	int row = 1;
	int col = 1;

	int break_count = 0;
};

int n, m;

char map[1005][1005];
int dist[1005][1005][2];
bool is_visit[1005][1005][2];

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void bfs(int start_r, int start_c)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				dist[i][j][k] = -1;
			}
		}
	}

	queue<Node> queue;
	Node start_node;
	start_node.row = start_r;
	start_node.col = start_c;
	dist[start_node.row][start_node.col][start_node.break_count] = 1;
	is_visit[start_node.row][start_node.col][start_node.break_count] = true;

	queue.push(start_node);

	while (!queue.empty())
	{
		Node cur_node = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_r = cur_node.row + dr[i];
			int next_c = cur_node.col + dc[i];

			if (next_r <= 0 || next_r > n || next_c <= 0 || next_c > m) continue;
			
			Node next_node;
			next_node.row = next_r;
			next_node.col = next_c;
			next_node.break_count = cur_node.break_count;

			if (map[next_r][next_c] == '1')
			{
				if (next_node.break_count == 0)
				{
					next_node.break_count++;
				}
				else
				{
					continue;
				}
			}

			if (is_visit[next_r][next_c][next_node.break_count]) continue;

			dist[next_r][next_c][next_node.break_count] = dist[cur_node.row][cur_node.col][cur_node.break_count] + 1;
			is_visit[next_node.row][next_node.col][next_node.break_count] = true;

			queue.push(next_node);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}

	bfs(1, 1);

	if (dist[n][m][0] == -1 || dist[n][m][1] == -1)
	{
		cout << max(dist[n][m][0], dist[n][m][1]);
	}
	else
	{
		cout << min(dist[n][m][0], dist[n][m][1]);
	}
}