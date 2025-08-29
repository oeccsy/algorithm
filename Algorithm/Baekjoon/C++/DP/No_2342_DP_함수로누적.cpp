#include <iostream>

using namespace std;

int d[100005][5][5]; // i 번째 왼발 위치, 오른발 위치일 때 최댓 값

int cost(int prev, int next)
{
	if (prev == next) return 1;
	if (prev == 0) return 2;
	if (prev % 2 == next % 2) return 4;

	return 3;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int left = 0;
	int right = 0;
	int index = 0;

	for (int i = 0; i < 100005; ++i)
	{
		for (int j = 0; j <= 4; ++j)
		{
			for (int k = 0; k <= 4; ++k)
			{
				d[i][j][k] = 10000000;
			}
		}
	}

	d[0][0][0] = 0;

	while (true)
	{
		int input;
		cin >> input;

		if (input == 0) break;
		++index;

		for (int i = 0; i <= 4; ++i)
		{
			for (int j = 0; j <= 4; ++j)
			{
				if (d[index - 1][i][j] >= 10000000) continue;

				d[index][input][j] = min(d[index][input][j], d[index - 1][i][j] + cost(i, input));
				d[index][i][input] = min(d[index][i][input], d[index - 1][i][j] + cost(j, input));
			}
		}
	}

	int answer = 10000000;

	for (int i = 0; i <= 4; ++i)
	{
		for (int j = 0; j <= 4; ++j)
		{
			answer = min(answer, d[index][i][j]);
		}
	}

	cout << answer;

	return 0;
}