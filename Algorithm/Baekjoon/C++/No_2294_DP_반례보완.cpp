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
      
      if(coins[i] <= k) d[coins[i]] = 1;
    }
    
    sort(&coins[0], &coins[n], cmp);

    for(int j=0; j<n; j++)
    {
      int coin_value = coins[j];
      if(coin_value > k) continue;

      for(int i=coin_value; i<=k; i++)
      {
        if(d[i-coin_value] == 0) continue;
        
        if(d[i] == 0) d[i] = d[i-coin_value]+1;
        else d[i] = min(d[i], d[i-coin_value]+1);
      }
    }

    if(d[k] > 0)
      cout << d[k];
    else
      cout << -1;
}