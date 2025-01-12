#include <iostream>
#include <algorithm>

using namespace std;

int coins[105];
int d[10005]; // [i]원을 최소의 동전만으로 만들기 위해 필요한 동전의 갯수

bool cmp(int a, int b)
{
  return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
      cin >> coins[i];
    }

    for(int i=1; i<=k; i++)
    {
      d[i] = 100005;
    }

    for(int j=0; j<n; j++)
    {
      int coin_value = coins[j];

      for(int i=1; i<=k; i++)
      {
        if(i-coin_value < 0) continue;
        d[i] = min(d[i], d[i-coin_value]+1);
      }
    }

    if(d[k] == 100005)
      cout << -1;
    else
      cout << d[k];
}