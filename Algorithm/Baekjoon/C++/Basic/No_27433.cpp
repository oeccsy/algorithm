#include <iostream>

using namespace std;

long long Factorial(int num)
{
    if(num == 1 || num == 0) return 1;
    return num * Factorial(num-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << Factorial(n);
}