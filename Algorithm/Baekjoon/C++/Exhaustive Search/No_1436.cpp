#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int findCount = 0;
	int curNum = 1;

	while (findCount < n)
	{
		++curNum;

		bool find = false;
		string num_to_str = to_string(curNum);

		int streakCount = 0;
		for (auto& num : num_to_str)
		{
			if (num == '6')
			{
				++streakCount;
			}
			else
			{
				streakCount = 0;
			}

			if (streakCount >= 3)
			{
				find = true;
				break;
			}
		}

		if (find) ++findCount;
	}

	cout << curNum;
}