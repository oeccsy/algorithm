#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> list;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		list.push_back(i);
	}

	auto it = list.begin();

	cout << "<";

	while (!list.empty())
	{
		for (int i = 0; i < k - 1; ++i)
		{
			++it;

			if (it == list.end()) it = list.begin();
		}

		if (list.size() > 1)
		{
			cout << *it << ", ";
		}
		else
		{
			cout << *it << ">";
		}

		it = list.erase(it);
		if (it == list.end()) it = list.begin();
	}
}