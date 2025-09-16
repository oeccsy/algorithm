#include <iostream>

using namespace std;


// d[i][j][j] = 길이가 i, 마지막 수가 j, mask가 j인 숫자의 수
int d[101][10][1 << 10];

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int j = 1; j < 10; ++j)
	{
		d[1][j][1 << j] = 1;
	}


	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < (1 << 10); ++k)
			{
				if (j - 1 >= 0)
				{
					int nextLast = j - 1;
					int nextMask = k | (1 << nextLast);

					d[i + 1][nextLast][nextMask] += d[i][j][k];
					d[i + 1][nextLast][nextMask] %= 1000000000;
				}

				if (j + 1 <= 9)
				{
					int nextLast = j + 1;
					int nextMask = k | (1 << nextLast);

					d[i + 1][nextLast][nextMask] += d[i][j][k];
					d[i + 1][nextLast][nextMask] %= 1000000000;
				}
			}
		}
	}

	int answer = 0;

	for (int j = 0; j < 10; ++j)
	{
		answer += d[n][j][(1 << 10) - 1];
		answer %= 1000000000;
	}

	cout << answer;
}