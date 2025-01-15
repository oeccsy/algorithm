#include <iostream>
#include <array>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 42> remain = {0, };
	int result = 0;
	
	for(int i=0; i<10; i++)
	{
		int input;
		int remain_of_input;
		cin >> input;
		remain_of_input = input % 42;

		remain[remain_of_input]++;
	}

	for(int i=0; i<42; i++)
	{
		if(remain[i] != 0) result++;
	}

	cout << result;

   
}