#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool RabinKarp(string& str, int len)
{
	// 길이를 기준으로 수행 -> 해시테이블 추가
	unordered_map<int, vector<int>> hash_st_table;

	int window_hash = 0;
	int power = 1;
	int mod = 1000007;

	for (int i = 0; i < len; ++i)
	{
		window_hash = (window_hash * 2 + str[i]) % mod;
		power = (i == 0) ? 1 : (power * 2) % mod;
	}

	for (int window_st = 0; window_st + len <= str.size(); ++window_st)
	{
		vector<int>& st_vec = hash_st_table[window_hash];

		if (!st_vec.empty())
		{
			bool match = false;

			for (auto exist_st : st_vec)
			{
				match = true;

				for (int i = 0; i < len; ++i)
				{
					if (str[window_st + i] != str[exist_st + i])
					{
						match = false;
						break;
					}
				}

				if (match) break;
			}

			if (match) return true;
		}

		st_vec.push_back(window_st);

		window_hash = (window_hash - (str[window_st] * power % mod) + mod) % mod;
		window_hash = (window_st + len < str.size()) ? (window_hash * 2 + str[window_st + len]) : 0;
	}

	return false;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int l;
	cin >> l;

	string str;
	cin >> str;

	// 문자열 길이 <= 200,000
	// 목표 : O(n log n)

	int left = 0;
	int right = str.size();

	int answer = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		bool match = RabinKarp(str, mid);

		if (match)
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
}