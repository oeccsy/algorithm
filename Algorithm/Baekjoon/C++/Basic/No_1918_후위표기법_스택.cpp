#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string command;
	cin >> command;

	stack<char> opers;

	for (int i = 0; i < command.size(); ++i)
	{
		char oper = command[i];

		if ('A' <= oper && oper <= 'Z')
		{
			cout << oper;
		}
		else if (oper == '+' || oper == '-')
		{
			while (!opers.empty())
			{
				char target = opers.top();
				if (target == '(') break;

				cout << target;
				opers.pop();
			}

			opers.push(oper);
		}
		else if (oper == '*' || oper == '/')
		{
			while (!opers.empty())
			{
				char target = opers.top();
				if (target == '(' || target == '+' || target == '-') break;

				cout << target;
				opers.pop();
			}

			opers.push(oper);
		}
		else if (oper == '(')
		{
			opers.push(oper);
		}
		else if (oper == ')')
		{
			while (!opers.empty())
			{
				char target = opers.top();
				opers.pop();

				if (target == '(') break;
				cout << target;
			}
		}
	}

	while (!opers.empty())
	{
		char target = opers.top();
		opers.pop();

		cout << target;
	}
}