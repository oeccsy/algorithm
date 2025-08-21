#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		string p;
		cin >> p;

		int n;
		cin >> n;

		vector<int> arr;

		char ch;
		cin >> ch;

		for (int i = 0; i < n; ++i)
		{
			int input;
			cin >> input;

			arr.push_back(input);

			if (i < n - 1) cin >> ch;
		}
		cin >> ch;

		bool is_reverse = false;
		bool is_error = false;
		int left = 0;
		int right = n - 1;

		for (char command : p)
		{
			if (command == 'R') is_reverse = !is_reverse;

			if (command == 'D')
			{
				if (left > right) is_error = true;

				if (is_reverse)
				{
					--right;
				}
				else
				{
					++left;
				}
			}
		}


		if (is_error)
		{
			cout << "error" << '\n';
		}
		else
		{
			cout << '[';

			if (is_reverse)
			{
				for (int i = right; i >= left; --i)
				{
					cout << arr[i];

					if (i != left) cout << ',';
				}
			}
			else
			{
				for (int i = left; i <= right; ++i)
				{
					cout << arr[i];

					if (i != right) cout << ',';
				}
			}

			cout << ']' << '\n';
		}
	}
}