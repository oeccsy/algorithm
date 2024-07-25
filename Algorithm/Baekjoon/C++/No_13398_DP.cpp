#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[100005][2]; // i번째 수 부터 시작했을 때 최댓값, j가지 경우(수 1개 제거 한 경우, 안한 경우)

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> nums;

  for(int i=0; i<n; i++)
  {
    int input;
    cin >> input;

    nums.push_back(input);
  }

  int ans = d[n-1][0] = nums[n-1];

  for(int i=n-2; i>=0; i--)
  {
    d[i][0] = max(nums[i] + d[i+1][0], nums[i]);
    d[i][1] = max(nums[i] + d[i+1][1], d[i+1][0]);

    ans = max({ans, d[i][0], d[i][1]});
  }

  cout << ans;
}