#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[50];

bool Compare(string& a, string& b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }

    int a_sum = 0;
    int b_sum = 0;

    for (int i = 0; i < a.length(); i++)
    {
        if (0 < a[i] - '0' && a[i] - '0' < 10)
        {
            a_sum += a[i] - '0';
        }
    }

    for (int i = 0; i < b.length(); i++)
    {
        if (0 < b[i] - '0' && b[i] - '0' < 10)
        {
            b_sum += b[i] - '0';
        }
    }

    if (a_sum != b_sum)
    {
        return a_sum < b_sum;
    }

    return a < b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        arr[i] = input;
    }

    sort(arr, arr + n, Compare);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
}
