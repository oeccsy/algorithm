#include <iostream>
#include <algorithm>

using namespace std;

int d[3][2];    //[i]에 위치할 때 최대/최소[j] 점수 합
int temp[3][2]; //d를 저장하는 임시 배열

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;

  int a, b, c;
  cin >> a >> b >> c;
  d[0][0] = d[0][1] = a;
  d[1][0] = d[1][1] = b;
  d[2][0] = d[2][1] = c;

  for(int i=1; i<n; i++)
  {
    cin >> a >> b >> c;

    for(int r=0; r<3; r++)
      for(int c=0; c<2; c++)
        temp[r][c] = d[r][c];

    d[0][0] = max(temp[0][0], temp[1][0]) + a;
    d[0][1] = min(temp[0][1], temp[1][1]) + a;

    d[1][0] = max({temp[0][0], temp[1][0], temp[2][0]}) + b;
    d[1][1] = min({temp[0][1], temp[1][1], temp[2][1]}) + b;

    d[2][0] = max(temp[1][0], temp[2][0]) + c;
    d[2][1] = min(temp[1][1], temp[2][1]) + c;
  }

  int ans_max = max({d[0][0], d[1][0], d[2][0]});
  int ans_min = min({d[0][1], d[1][1], d[2][1]});

  cout << ans_max << " " << ans_min;
}
