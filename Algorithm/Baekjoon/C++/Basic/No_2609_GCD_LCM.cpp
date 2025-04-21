#include <iostream>

using namespace std;

int GCD(int num1, int num2)
{
    if(num1 < num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;        
    }

    int r = num1 % num2;

    return r ? GCD(num2, r) : num2;
}

int LCM(int num1, int num2, int gcd)
{
    return num1 * num2 / gcd;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num1, num2;
    cin >> num1 >> num2;

    int gcd = GCD(num1, num2);
    int lcm = LCM(num1, num2, gcd);

    cout << gcd << '\n' << lcm;
}