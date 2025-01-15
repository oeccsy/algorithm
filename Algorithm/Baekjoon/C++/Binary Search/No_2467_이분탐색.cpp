#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> liq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 혼합 -> 특성값 합으로 0에 가장 가까운 수
    // 혼합하여 0에 가장 가까운 용액 만들려고 함
    // [-99, -2, -1, 4 , 98] 정렬된 순서로 주어짐
    // 특성값이 0에 가장 가까운 것은?
    // 두 용액을 혼합했을 때 특성값이 0에 가장 가까운가?

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        liq.push_back(input);
    }

    vector<int> ans;
    int min_abs = 2000000005;

    for (int i = 0; i < n; i++)
    {
        int best = 0 - liq[i];

        auto best_iter = lower_bound(liq.begin(), liq.end(), best);
        auto best_iter_big = best_iter + 1;
        auto best_iter_small = best_iter - 1;

        vector<vector<int>::iterator> iters;
        iters.push_back(best_iter);
        iters.push_back(best_iter_big);
        iters.push_back(best_iter_small);

        for(auto iter : iters)
        {
            int index = iter - liq.begin();
            if(index >= liq.size()) continue;
            if(index == i) continue;

            int cur_abs = abs(*iter + liq[i]);
            if(cur_abs < min_abs)
            {
                ans.clear();
                ans.push_back(liq[i]);
                ans.push_back(*iter);
                min_abs = abs(*iter + liq[i]);
            }
        }
    }

    sort(ans.begin(), ans.end());

    for (int value : ans)
    {
        cout << value << " ";
    }
}