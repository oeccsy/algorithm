#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 빨간 파란 구슬 하나씩 넣음
// 빨가 구슬을 빼내는 게임
// n x m 직사각형 보드
// 보드에는 구멍이 하나 나머지는 막힘
// 파란구슬은 구멍에 들어가면 안됨
// 중력을 이용해 이리저리 굴려야함
// 공은 동시에 움직인다.

// 보드 상태가 주어졌을 때 몇번만에 빨간 구슬을 빼낼 수 있을까?

struct Position
{
	int row;
	int col;

	bool operator==(Position& other)
	{
		return (row == other.row && col == other.col);
	}
};

int n, m;
char board[10][10];

int answer = 11;

void MoveToTop(Position& red, Position& blue)
{
	Position& first = (red.row < blue.row) ? red : blue;
	Position& second = (red.row < blue.row) ? blue : red;

	while (true)
	{
		Position nextPos = { first.row - 1, first.col };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			first = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			first = nextPos;
		}
	}

	while (true)
	{
		Position nextPos = { second.row - 1, second.col };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			second = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			second = nextPos;
		}
	}
}

void MoveToBottom(Position& red, Position& blue)
{
	Position& first = (red.row < blue.row) ? blue : red;
	Position& second = (red.row < blue.row) ? red : blue;

	while (true)
	{
		Position nextPos = { first.row + 1, first.col };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			first = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			first = nextPos;
		}
	}

	while (true)
	{
		Position nextPos = { second.row + 1, second.col };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			second = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			second = nextPos;
		}
	}
}

void MoveToLeft(Position& red, Position& blue)
{
	Position& first = (red.col < blue.col) ? red : blue;
	Position& second = (red.col < blue.col) ? blue : red;

	while (true)
	{
		Position nextPos = { first.row, first.col - 1 };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			first = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			first = nextPos;
		}
	}

	while (true)
	{
		Position nextPos = { second.row, second.col - 1 };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			second = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			second = nextPos;
		}
	}
}

void MoveToRight(Position& red, Position& blue)
{
	Position& first = (red.col < blue.col) ? blue : red;
	Position& second = (red.col < blue.col) ? red : blue;

	while (true)
	{
		Position nextPos = { first.row, first.col + 1 };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			first = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			first = nextPos;
		}
	}

	while (true)
	{
		Position nextPos = { second.row, second.col + 1 };

		if (board[nextPos.row][nextPos.col] == 'O')
		{
			second = nextPos;
			break;
		}
		else if (nextPos == red || nextPos == blue || board[nextPos.row][nextPos.col] == '#')
		{
			break;
		}
		else
		{
			second = nextPos;
		}
	}
}

void Solve(int depth, Position red, Position blue)
{
	if (board[blue.row][blue.col] == 'O') return;

	if (board[red.row][red.col] == 'O')
	{
		answer = min(answer, depth);
		return;
	}

	if (depth >= 10) return;

	{
		Position nextRed = red;
		Position nextBlue = blue;
		MoveToTop(nextRed, nextBlue);
		Solve(depth + 1, nextRed, nextBlue);
	}

	{
		Position nextRed = red;
		Position nextBlue = blue;
		MoveToBottom(nextRed, nextBlue);
		Solve(depth + 1, nextRed, nextBlue);
	}

	{
		Position nextRed = red;
		Position nextBlue = blue;
		MoveToLeft(nextRed, nextBlue);
		Solve(depth + 1, nextRed, nextBlue);
	}

	{
		Position nextRed = red;
		Position nextBlue = blue;
		MoveToRight(nextRed, nextBlue);
		Solve(depth + 1, nextRed, nextBlue);
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	Position redStart;
	Position blueStart;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 'R') redStart = { i, j };
			if (board[i][j] == 'B') blueStart = { i, j };
		}
	}

	Solve(0, redStart, blueStart);

	cout << ((answer <= 10) ? answer : -1);
}