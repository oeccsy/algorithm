#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> trees;

// 높이를 h로 지정 했을 때, 원하는 만큼의 나무를 집으로 가져갈 수 있나/없나
//

bool is_possible(int m, int h)
{
	long long sum = 0;

	for (int height : trees)
	{
		sum += (height > h) ? height - h : 0;
	}

	return sum >= m;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int tree;
		cin >> tree;

		trees.push_back(tree);
	}

	int left = 0;
	int right = 1000000000;
	int answer = 0;

	while (left <= right)
	{
		int pred = (left + right) / 2;

		if (is_possible(m, pred))
		{
			answer = pred;
			left = pred + 1;
		}
		else
		{
			right = pred - 1;
		}
	}

	cout << answer;
}