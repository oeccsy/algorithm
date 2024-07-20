#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005][1005];
int d[1005][1005];  // [i-1][j-1]에서 정사각형 그리기를 시작 했을 때 한 변의 길이

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        char input;
        cin >> input;
        
        arr[i][j] = input - '0';
      }
    }

    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        if(arr[i-1][j-1] == 1)
        {
          d[i][j] = min({d[i-1][j-1], d[i-1][j], d[i][j-1]}) + 1;
        }
      }
    }
    
    int max_d = 0;

    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        if(max_d < d[i][j]) max_d = d[i][j];
      }
    }

    cout << max_d * max_d;
}