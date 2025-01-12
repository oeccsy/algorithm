#include <iostream>

using namespace std;

long long d[101][10]; // [i] 번째 수가 [j] 로 끝나는 경우의 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    d[1][0] = 0;
    for(int j=1; j<=9; j++)
    {
        d[1][j] = 1;
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=9; j++)
        {
            switch(j)
            {
            case 0 :
                d[i][0] = d[i-1][1];
                d[i][0] %= 1000000000;
                break;
            case 9 :
                d[i][9] = d[i-1][8];
                d[i][9] %= 1000000000;
                break;
            default :
                d[i][j] = d[i-1][j-1] + d[i-1][j+1];
                d[i][j] %= 1000000000;
                break;
            }
        }
    }

    long long result = 0;
    for(int j=0; j<=9; j++)
    {
        result += d[n][j];
        result %= 1000000000;
    }

    cout << result;
}