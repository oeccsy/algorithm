#include <iostream>
#include <algorithm>

using namespace std;

int n;

int s[15];
int b[15];

int min_diff = 1000000001;

void solve(int depth, int s_sum, int b_sum, int use_count)
{
	if (depth == n)
	{
		if (use_count == 0) return;

		int cur_diff = (s_sum > b_sum) ? s_sum - b_sum : b_sum - s_sum;
		min_diff = min(min_diff, cur_diff);

		return;
	}

	solve(depth + 1, s_sum * s[depth], b_sum + b[depth], use_count + 1);
	solve(depth + 1, s_sum, b_sum, use_count);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> b[i];
	}

	solve(0, 1, 0, 0);

	cout << min_diff;
}