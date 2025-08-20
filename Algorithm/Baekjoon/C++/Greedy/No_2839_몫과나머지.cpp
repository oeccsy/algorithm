#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 일단 5kg 봉지 가능한 사용
	// 나머지 0 -> 성공
	// 나머지 1 -> 1개 제거 ->  6 -> 2개 추가
	// 나머지 2 -> 2개 제거 -> 12 -> 4개 추가
	// 나머지 3 -> 1개 추가
	// 나머지 4 -> 1개 제거 ->  9 -> 3개 추가

	int use_count = 0;
	use_count += n / 5;

	switch (n % 5)
	{
	case 0:
		cout << use_count;
		break;
	case 1:
		if (use_count < 1) cout << -1;
		else cout << use_count - 1 + 2;
		break;
	case 2:
		if (use_count < 2) cout << -1;
		else cout << use_count - 2 + 4;
		break;
	case 3:
		cout << use_count + 1;
		break;
	case 4:
		if (use_count < 1) cout << -1;
		else cout << use_count - 1 + 3;
		break;
	}
}


// 좀 더 깔끔한 그리디 방식
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int use_count = 0;
	use_count += n / 5;
	n = n % 5;

	while (use_count >= 0)
	{
		if (n % 3 == 0)
		{
			cout << use_count + (n / 3);
			return 0;
		}

		--use_count;
		n += 5;
	}

	cout << -1 << endl;
}