#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int d[1005][1005]; // str1의 i개 문자를 고려했을때, str2의 j개 문자를 고려했을 때 최대 길이

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	string str1;
	string str2;

	cin >> str1;
	cin >> str2;

	for (int i = 1; i <= str1.size(); ++i)
	{
		for (int j = 1; j <= str2.size(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				d[i][j] = (i - 1 < 0 || j - 1 < 0) ? 1 : d[i - 1][j - 1] + 1;
			}
			else
			{
				int prev_row = (j - 1 < 0) ? 0 : d[i - 1][j];
				int prev_col = (i - 1 < 0) ? 0 : d[i][j - 1];

				d[i][j] = max(prev_row, prev_col);
			}
		}
	}

	int length = d[str1.size()][str2.size()];

	stack<char> path;
	pair<int, int> cur = { str1.size(), str2.size() };

	while (cur.first > 0 && cur.second > 0)
	{
		int cur_len = d[cur.first][cur.second];
		int prev_row_len = d[cur.first - 1][cur.second];
		int prev_col_len = d[cur.first][cur.second - 1];

		if (prev_row_len < cur_len && prev_col_len < cur_len)
		{
			path.push(str1[cur.first - 1]);
			cur = { cur.first - 1, cur.second - 1 };
		}
		else if (prev_row_len == cur_len)
		{
			cur = { cur.first - 1, cur.second };
		}
		else
		{
			cur = { cur.first, cur.second - 1 };
		}
	}

	cout << length << '\n';

	while (!path.empty())
	{
		cout << path.top();
		path.pop();
	}
}