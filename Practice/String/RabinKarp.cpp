#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int RabinKarpBaseK(const string& str, const string& pattern)
{
	if (pattern.size() > str.size()) return -1;

	const int k_base = 26;
	int str_hash = 0;
	int pattern_hash = 0;
	int power_pattern = 1;

	for (int i = 0; i < pattern.size(); ++i)
	{
		power_pattern = i ? power_pattern * k_base : 1;
		str_hash = str_hash * k_base + str[i];
		pattern_hash = pattern_hash * k_base + pattern[i];
	}

	for (int i = pattern.size(); i < str.size(); ++i)
	{
		if (str_hash == pattern_hash)
		{
			if (str.substr(i - pattern.size(), pattern.size()) == pattern)
			{
				return i - pattern.size();
			}
		}

		str_hash -= str[i - pattern.size()] * power_pattern;
		str_hash = str_hash * k_base + str[i];
	}

	if (str_hash == pattern_hash)
	{
		if (str.substr(str.size() - pattern.size(), pattern.size()) == pattern)
		{
			return str.size() - pattern.size();
		}
	}

	return -1;
}

int RabinKarpBase2(const string& str, const string& pattern)
{
	if (pattern.size() > str.size()) return -1;
	
	int str_hash = 0;
	int pattern_hash = 0;
	
	for (int i = 0; i < pattern.size(); ++i)
	{
		char str_char = str[i];
		char pattern_char = pattern[i];

		str_hash = str_hash * 2 + str[i];
		pattern_hash = pattern_hash * 2 + pattern[i];
	}

	for (int i = 0; i <= str.size() - pattern.size(); ++i)
	{
		if (str_hash == pattern_hash)
		{
			string str_substr = str.substr(i, pattern.size());
			bool match = str_substr == pattern;
			
			if (match) return i;
		}

		if (i < str.size() - pattern.size())
		{
			str_hash -= str[i] * (1 << (pattern.size() - 1));
			str_hash = str_hash * 2 + str[i + pattern.size()];
		}
	}

	return -1;
}

int RabinKarpBase2WithMod(const string& str, const string& pattern)
{
	if (pattern.size() > str.size()) return -1;

	int str_hash = 0;
	int pattern_hash = 0;
	int power_pattern = 1;
	int mod = 31;

	for (int i = 0; i < pattern.size(); ++i)
	{
		str_hash = (str_hash * 2 + str[i]) % mod;
		pattern_hash = (pattern_hash * 2 + pattern[i]) % mod;
		power_pattern = (i == 0) ? 1 : (power_pattern * 2) % mod;
	}

	for (int i = 0; i <= str.size() - pattern.size(); ++i)
	{
		if (str_hash == pattern_hash)
		{
			string str_substr = str.substr(i, pattern.size());
			bool match = str_substr == pattern;

			if (match) return i;
		}

		if (i < str.size() - pattern.size())
		{
			str_hash = (str_hash - ((str[i] * power_pattern) % mod) + mod) % mod;
			str_hash = (str_hash * 2 + str[i + pattern.size()]) % mod;
		}
	}

	return -1;
}

bool RabinKarpTwoPointer(string& str, int pattern_st, int pattern_en)
{
	int window_st = 0;
	int window_en = pattern_en - pattern_st;

	int window_hash = 0;
	int pattern_hash = 0;
	int pattern_power = 1;
	int mod = 31;

	for (int i = 0; i < pattern_en - pattern_st; ++i)
	{
		char window_char = str[i];
		char pattern_char = str[pattern_st + i];

		window_hash = (window_hash * 2 + window_char) % mod;
		pattern_hash = (pattern_hash * 2 + pattern_char) % mod;
		pattern_power = (i == 0) ? 1 : (pattern_power * 2) % mod;
	}

	while (window_en <= str.size())
	{
		if (window_hash == pattern_hash && window_st != pattern_st)
		{
			bool match = true;

			for (int i = 0; i < pattern_en - pattern_st; ++i)
			{
				if (str[window_st + i] != str[pattern_st + i])
				{
					match = false;
					break;
				}
			}

			if (match) return true;
		}

		if (window_en < str.size())
		{
			window_hash = (window_hash - (str[window_st] * pattern_power % mod) + mod) % mod;
			window_hash = (window_hash * 2 + str[window_en]) % mod;
		}

		++window_st;
		++window_en;
	}

	return false;
}

bool RabinKarpWithLen(string& str, int len)
{
	// 길이를 기준으로 수행 -> 해시테이블 추가
	// 반환값 +@ 이분탐색
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int k_1 = RabinKarpBaseK("testtesttest", "ttes");
	int k_2 = RabinKarpBaseK("asdfasdfasdf", "zzzzz");

	int t_1 = RabinKarpBase2("testtesttest", "ttes");
	int t_2 = RabinKarpBase2("asdfasdfasdf", "zzzzz");

	int m_1 = RabinKarpBase2WithMod("testtesttest", "ttes");
	int m_2 = RabinKarpBase2WithMod("asdfasdfasdf", "zzzzz");

	cout << "k_1 : " << k_1 << '\n';
	cout << "k_2 : " << k_2 << '\n';
	cout << "t_1 : " << t_1 << '\n';
	cout << "t_2 : " << t_2 << '\n';
	cout << "m_1 : " << m_1 << '\n';
	cout << "m_2 : " << m_2 << '\n';
}
