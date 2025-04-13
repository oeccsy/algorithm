#include <iostream>
#include <algorithm>

using namespace std;

int d_max[3] = {0, 0, 0};
int d_min[3] = {0, 0, 0};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;

  for(int i=1; i<=n; i++)
  {
    int left, middle, right;
    cin >> left >> middle >> right;

    int temp[3] = {0, 0, 0};

    temp[0] = max(d_max[0], d_max[1]) + left;
    temp[1] = max(d_max[0], max(d_max[1], d_max[2])) + middle;
    temp[2] = max(d_max[1], d_max[2]) + right;

    d_max[0] = temp[0];
    d_max[1] = temp[1];
    d_max[2] = temp[2];

    temp[0] = min(d_min[0], d_min[1]) + left;
    temp[1] = min(d_min[0], min(d_min[1], d_min[2])) + middle;
    temp[2] = min(d_min[1], d_min[2]) + right;

    d_min[0] = temp[0];
    d_min[1] = temp[1];
    d_min[2] = temp[2];
  }

  cout << max(d_max[0], max(d_max[1], d_max[2])) << " " << min(d_min[0], min(d_min[1], d_min[2]));
}
