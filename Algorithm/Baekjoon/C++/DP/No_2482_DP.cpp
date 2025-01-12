#include <iostream>

using namespace std;

int d[1005][1005]; // d[n][k] = nCk

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for(int i=1; i<=n; i++)
  {
    d[i][0] = 1;
    d[i][1] = i;
  }

  for(int i=1; i<=n; i++)
  {
    for(int j=2; j<=n; j++)
    {
      if(i < j) break;
      d[i][j] = (d[i-1][j-1] + d[i-1][j]) % 1000000003;
    }
  }

  cout << (d[n-k-1][k-1] + d[n-k][k]) % 1000000003;
}