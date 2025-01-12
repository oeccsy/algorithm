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

      for(int i=1; i<=k; i++)
      {
        if(i-coin_value <= 0) continue;
        if(d[i-coin_value] == 0) continue;
        if(d[i] > 0) continue;
        
        d[i] = d[i-coin_value]+1;
        // 놓친점 : 비싼 동전이 항상 싼 동전을 대신할 수 없음
        // 비싼 동전들로만 금액을 만들었을 때, 그 금액의 첫 번째 업데이트에서 항상 최적의 동전 갯수가 완성되지 않음
        // 예시
        // n = 4, k = 69
        // coin = {67, 17, 13, 1}
        // 출력 : 5
        // 정답 : 3
      }
    }

    if(d[k] > 0)
      cout << d[k];
    else
      cout << -1;
}