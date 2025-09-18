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
	else
	{
		Vector minL1 = { min(p1.x, p2.x), min(p1.y, p2.y) };
		Vector maxL1 = { max(p1.x, p2.x), max(p1.y, p2.y) };
		Vector minL2 = { min(p3.x, p4.x), min(p3.y, p4.y) };
		Vector maxL2 = { max(p3.x, p4.x), max(p3.y, p4.y) };

		bool isIntersects = true;

		if (maxL1.x < minL2.x) isIntersects = false;
		if (maxL1.y < minL2.y) isIntersects = false;
		if (maxL2.x < minL1.x) isIntersects = false;
		if (maxL2.y < minL1.y) isIntersects = false;

		if (isIntersects)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
}