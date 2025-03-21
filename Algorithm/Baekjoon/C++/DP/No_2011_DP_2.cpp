#include <iostream>
#include <string>

using namespace std;

int d[5005][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string code;
    cin >> code;

    int size = code.size();

    if(size < 2)
    {
        cout << ((code[0] == '0') ? 0 : 1);
        return 0;
    }
    
    d[size-1][0] = (code[size-1] == '0') ? 0 : 1;
    d[size-1][1] = 0;

    int one_digit = code[size-2];
    int two_digits = (code[size-2] - '0') * 10 + code[size-1] - '0';
    d[size-2][0] = (one_digit == '0') ? 0 : d[size-1][0] + d[size-1][1];
    d[size-2][1] = (two_digits < 10 || 26 < two_digits) ? 0 : 1;
    
    for(int i=size-3; i>=0; i--)
    {
        int one_digit = code[i];
        int two_digits = (code[i] - '0') * 10 + code[i+1] - '0';
        d[i][0] = (one_digit == '0') ? 0 : d[i+1][0] + d[i+1][1];
        d[i][1] = (two_digits < 10 || 26 < two_digits) ? 0 : d[i+2][0] + d[i+2][1];

        d[i][0] %= 1000000;
        d[i][1] %= 1000000;
    }

    cout << (d[0][0] + d[0][1]) % 1000000;
}