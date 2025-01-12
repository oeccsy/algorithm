#include <iostream>
#include <algorithm>

using namespace std;

int plum[1005] = {0,};
int d[1005][3][35] = {0,};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    int w;

    cin >> t >> w;
    for(int i=1; i<=t; i++)
    {
      int line_num;
      cin >> line_num;

      plum[i] = line_num;
    }

    d[1][1][0] = (plum[1] == 1) ? 1 : 0;
    d[1][2][1] = (plum[1] == 2) ? 1 : 0;

    for(int i=2; i<=t; i++)
    {
      for(int j=0; j<=w; j++)
      {
          if(plum[i] == 1)
          {
            if(j == 0)
            {
              d[i][1][j] = d[i-1][1][j] + 1;
              d[i][2][j] = d[i-1][2][j];
            }
            else
            {
              d[i][1][j] = max(d[i-1][1][j], d[i-1][2][j-1]) + 1;
              d[i][2][j] = max(d[i-1][2][j], d[i-1][1][j-1]);
            }
          }
          else
          {
            if(j == 0)
            {
              d[i][1][j] = d[i-1][1][j];
              d[i][2][j] = d[i-1][2][j] + 1;
            }
            else
            {
              d[i][1][j] = max(d[i-1][1][j], d[i-1][2][j-1]);
              d[i][2][j] = max(d[i-1][2][j], d[i-1][1][j-1]) + 1;
            }
          }
      }
    }

    int result = 0;

    for(int line_num=1; line_num<=2; line_num++)
    {
      for(int temp_w=0; temp_w<=w; temp_w++)
      {
        int plum_count = d[t][line_num][temp_w];
        if(plum_count > result) result = plum_count;
      }
    }

    cout << result;
}