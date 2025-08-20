#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unordered_set<int> set;

	int m;
	cin >> m;

	while (m--)
	{
		string command;
		int value;

		cin >> command;

		if (command == "add")
		{
			cin >> value;
			set.insert(value);
		}
		else if (command == "remove")
		{
			cin >> value;
			set.erase(value);
		}
		else if (command == "check")
		{
			cin >> value;
			cout << ((set.find(value) == set.end()) ? 0 : 1) << '\n';
		}
		else if (command == "toggle")
		{
			cin >> value;
			if (set.find(value) == set.end())
			{
				set.insert(value);
			}
			else
			{
				set.erase(value);
			}
		}
		else if (command == "all")
		{
			for (int i = 1; i <= 20; ++i) set.insert(i);
		}
		else if (command == "empty")
		{
			set.clear();
		}
	}
}