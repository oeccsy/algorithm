#include <iostream>

using namespace std;

int F(int index)
{
    if(index == 0) return 0;
    if(index == 1) return 1;

    return F(index-1) + F(index-2);
}

int main()
{
    int n;
    cin >> n;

    cout << F(n);
}