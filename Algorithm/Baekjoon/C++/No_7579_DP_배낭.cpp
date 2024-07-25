#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[105][10005]; // i번째 앱까지 고려했을 때 비용이 j인 경우 확보 가능한 메모리

struct App
{
  int memory;
  int cost;
};

vector<App *> apps;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    int memory_input;
    cin >> memory_input;

    App* new_app = new App();
    new_app->memory = memory_input;

    apps.push_back(new_app);
  }

  for (int i = 0; i < n; i++)
  {
    int cost_input;
    cin >> cost_input;

    apps[i]->cost = cost_input;
  }

  int ans = 10005;

  for (int j = 0; j < 10005; j++)
  {
    if (j - apps[0]->cost >= 0)
    {
      d[0][j] = apps[0]->memory;
    }

    if (d[0][j] >= m)
    {
      ans = min(ans, j);
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < 10005; j++)
    {
      if (j - apps[i]->cost >= 0)
      {
        d[i][j] = max(d[i - 1][j], d[i - 1][j - apps[i]->cost] + apps[i]->memory);
      }
      else
      {
        d[i][j] = d[i - 1][j];
      }

      if (d[i][j] >= m)
      {
        ans = min(ans, j);
      }
    }
  }

  cout << ans;
}