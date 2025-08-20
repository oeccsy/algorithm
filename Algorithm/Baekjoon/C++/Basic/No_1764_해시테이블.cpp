#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	unordered_set<string> never_heard;
	unordered_set<string> never_seen;
	vector<string> never_heard_seen;

	while (n--)
	{
		string str;
		cin >> str;
		never_heard.insert(str);
	}

	while (m--)
	{
		string str;
		cin >> str;
		never_seen.insert(str);
	}

	for (auto& str : never_heard)
	{
		if (never_seen.find(str) == never_seen.end()) continue;
		never_heard_seen.push_back(str);
	}

	sort(never_heard_seen.begin(), never_heard_seen.end());

	cout << never_heard_seen.size() << '\n';

	for (auto& str : never_heard_seen)
	{
		cout << str << '\n';
	}
}