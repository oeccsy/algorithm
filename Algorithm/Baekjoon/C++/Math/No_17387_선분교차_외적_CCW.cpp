#include <iostream>
#include <algorithm>

using namespace std;

struct Vector
{
	long long x, y;
};

int GetCCW(Vector p1, Vector p2, Vector p3)
{
	Vector p1p2 = { p2.x - p1.x, p2.y - p1.y };
	Vector p1p3 = { p3.x - p1.x, p3.y - p1.y };

	long long cross = p1p2.x * p1p3.y - p1p2.y * p1p3.x;

	if (cross > 0)
	{
		return 1;
	}
	else if (cross == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

bool Cmp(Vector& a, Vector& b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y < b.y;
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	Vector p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;

	int ccw1 = GetCCW(p1, p2, p3);
	int ccw2 = GetCCW(p1, p2, p4);

	int ccw3 = GetCCW(p3, p4, p1);
	int ccw4 = GetCCW(p3, p4, p2);

	if ((ccw1 * ccw2 > 0) || (ccw3 * ccw4 > 0))
	{
		cout << 0;
	}
	else if ((ccw1 * ccw2 < 0) && (ccw3 * ccw4 < 0))
	{
		cout << 1;
	}
	else if ((ccw1 * ccw2 == 0) && (ccw3 * ccw4 == 0))
	{
		if (Cmp(p2, p1)) swap(p1, p2);
		if (Cmp(p4, p3)) swap(p3, p4);

		if (Cmp(p2, p3) || Cmp(p4, p1))
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		cout << 1;
	}
}