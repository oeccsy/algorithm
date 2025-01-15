#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year;
    bool is_leap;
    cin >> year;

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        is_leap = true;
    }
    else
    {
        is_leap = false;
    }

    cout << is_leap;
    
}