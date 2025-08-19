#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N!의 맨 뒤부터 0의 연속 개수 구하기

	int n;
	cin >> n;

	int k = 0;
	int two_count = 0;
	int five_count = 0;

	while (k < n)
	{
		int temp_k = ++k;

		while (true)
		{
			if (temp_k % 2 == 0)
			{
				++two_count;
				temp_k /= 2;
			}
			else if (temp_k % 5 == 0)
			{
				++five_count;
				temp_k /= 5;
			}
			else
			{
				break;
			}
		}
	}

	cout << ((two_count < five_count) ? two_count : five_count);
}