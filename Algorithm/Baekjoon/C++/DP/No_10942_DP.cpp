#include <iostream>

using namespace std;

int arr[2005];
int d[2005][2005];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n;

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];

    d[i][i] = 1;
  }

  for(int dist=1; dist<n; dist++)
  {
    for(int i=0; i+dist<n; i++)
    {
      int j = i + dist;

      if(arr[i] == arr[j])
      {
        if(i+1 >= j-1)
        {
          d[i][j] = 1;
        }
        else
        {
          d[i][j] = d[i+1][j-1];
        }
      }
      else
      {
        d[i][j] = 0;
      }
    }
  }

  cin >> m;
  
  for(int i=0; i<m; i++)
  {
    int s, e;
    cin >> s >> e;

    cout << d[s-1][e-1] << '\n';
  }
}