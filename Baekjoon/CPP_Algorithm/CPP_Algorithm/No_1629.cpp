#include <iostream>

using namespace std;

long long a, b, c;
long long result = 1;

long long Multiply(long long a, long long b, long long c)
{
    if (b == 1) return a % c;

    if (b % 2 == 0)
    {
        long long result_of_half = Multiply(a, b/2, c);
        return (result_of_half * result_of_half) % c;
    }
    else
    {
        long long result_of_half = Multiply(a, (b-1)/2, c);
        return (((result_of_half * result_of_half) % c) * a) % c;           // overflow의 위험 때문에 중간에 %c 가 꼭 필요하다.
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;

    cout << Multiply(a, b, c);
}
