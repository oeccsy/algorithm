#include <iostream>
#include <algorithm>

using namespace std;

int d[100][4];  // [i]번째 열을 [j]번째 방법으로 채우는 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if(n % 2 == 1)
    {
      cout << 0;
      return 0;
    }

    d[2][0] = 3;
    d[2][1] = (n >= 4) ? 2 : 0;
    d[2][2] = 0;
    d[2][3] = 0;

    for(int i=4; i<=n; i+=2)
    {
      d[i][0] = 3 * (d[i-2][0] + d[i-2][3]);
      d[i][1] = 2 * (d[i-2][0] + d[i-2][3]);
      d[i][2] = d[i-2][1] + d[i-2][2];
      d[i][3] = d[i-2][1] + d[i-2][2];
    }

    cout << d[n][0] + d[n][3];
}