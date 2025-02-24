#include <iostream>
#include <string>

using namespace std;

int student[21] = { 0, };

const int MX = 3000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
	dat[tail++] = x;
}

void pop()
{
	student[dat[head]]--;
	head++;
}

int main()
{

	string name;
	int name_len;

	int n;
	int k;

	long long result = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> name;
		name_len = name.length();

		result += student[name_len];

		push(name_len);
		student[name_len]++;

		if (tail - head == k+1)
			pop();
	}

	cout << result;
}