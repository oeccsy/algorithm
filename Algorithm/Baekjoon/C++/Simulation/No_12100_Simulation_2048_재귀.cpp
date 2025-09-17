#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block
{
	int value;
	int recentMergedDepth = -1;
};

int n;
vector<vector<Block>> board;

int answer = 0;

void Print(vector<vector<Block>>& board)
{
	cout << '\n';

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board.size(); ++j)
		{
			cout << board[i][j].value << ' ';
		}

		cout << '\n';
	}

	cout << '\n';
}

vector<vector<Block>> MoveToTop(vector<vector<Block>>& board, int depth)
{
	vector<vector<Block>> result(board);

	for (int col = 0; col < n; ++col)
	{
		vector<Block> blocks;

		for (int row = 0; row < n; ++row)
		{
			if (board[row][col].value == 0) continue;

			Block newBlock = board[row][col];

			if (!blocks.empty() && blocks.back().value == newBlock.value && blocks.back().recentMergedDepth < depth)
			{
				blocks.back().value *= 2;
				blocks.back().recentMergedDepth = depth;
			}
			else
			{
				blocks.push_back(newBlock);
			}
		}

		while (blocks.size() < board.size())
		{
			blocks.push_back({ 0, -1 });
		}

		for (int row = 0; row < n; ++row)
		{
			result[row][col] = blocks[row];
		}
	}

	return result;
}

vector<vector<Block>> MoveToBottom(vector<vector<Block>>& board, int depth)
{
	vector<vector<Block>> result(board);

	for (int col = 0; col < n; ++col)
	{
		vector<Block> blocks;

		for (int row = n - 1; row >= 0; --row)
		{
			if (board[row][col].value == 0) continue;

			Block newBlock = board[row][col];

			if (!blocks.empty() && blocks.back().value == newBlock.value && blocks.back().recentMergedDepth < depth)
			{
				blocks.back().value *= 2;
				blocks.back().recentMergedDepth = depth;
			}
			else
			{
				blocks.push_back(newBlock);
			}
		}

		while (blocks.size() < board.size())
		{
			blocks.push_back({ 0, -1 });
		}

		for (int row = 0; row < n; ++row)
		{
			result[row][col] = blocks[(n - 1) - row];
		}
	}

	return result;
}

vector<vector<Block>> MoveToLeft(vector<vector<Block>>& board, int depth)
{
	vector<vector<Block>> result(board);

	for (int row = 0; row < n; ++row)
	{
		vector<Block> blocks;

		for (int col = 0; col < n; ++col)
		{
			if (board[row][col].value == 0) continue;

			Block newBlock = board[row][col];

			if (!blocks.empty() && blocks.back().value == newBlock.value && blocks.back().recentMergedDepth < depth)
			{
				blocks.back().value *= 2;
				blocks.back().recentMergedDepth = depth;
			}
			else
			{
				blocks.push_back(newBlock);
			}
		}

		while (blocks.size() < board.size())
		{
			blocks.push_back({ 0, -1 });
		}

		for (int col = 0; col < n; ++col)
		{
			result[row][col] = blocks[col];
		}
	}

	return result;
}

vector<vector<Block>> MoveToRight(vector<vector<Block>>& board, int depth)
{
	vector<vector<Block>> result(board);

	for (int row = 0; row < n; ++row)
	{
		vector<Block> blocks;

		for (int col = n - 1; col >= 0; --col)
		{
			if (board[row][col].value == 0) continue;

			Block newBlock = board[row][col];

			if (!blocks.empty() && blocks.back().value == newBlock.value && blocks.back().recentMergedDepth < depth)
			{
				blocks.back().value *= 2;
				blocks.back().recentMergedDepth = depth;
			}
			else
			{
				blocks.push_back(newBlock);
			}
		}

		while (blocks.size() < board.size())
		{
			blocks.push_back({ 0, -1 });
		}

		for (int col = 0; col < n; ++col)
		{
			result[row][col] = blocks[(n - 1) - col];
		}
	}

	return result;
}

void solve(int depth, vector<vector<Block>>& curBoard)
{
	if (depth == 5)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				answer = max(answer, curBoard[i][j].value);

		return;
	}

	auto moveToTop = MoveToTop(curBoard, depth);
	solve(depth + 1, moveToTop);

	auto moveToBottom = MoveToBottom(curBoard, depth);
	solve(depth + 1, moveToBottom);

	auto moveToLeft = MoveToLeft(curBoard, depth);
	solve(depth + 1, moveToLeft);

	auto moveToRight = MoveToRight(curBoard, depth);
	solve(depth + 1, moveToRight);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		vector<Block> row;

		for (int j = 0; j < n; ++j)
		{
			Block newNode;
			cin >> newNode.value;

			row.emplace_back(newNode);
		}

		board.emplace_back(row);
	}

	solve(0, board);

	cout << answer;
}