#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> liq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 용액 산성 / 알칼리성
    // 산성 1 ~ 10억
    // 알칼리성 -1 ~ -10억 

    // 3가지 용액 혼합 -> 특성값 합이 0에 가까워지도록

    // [-2, 6, -97, -6, 98]
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int value;
        cin >> value;
        liq.push_back(value);
    }

    sort(liq.begin(), liq.end());

    vector<int> ans;
    long long min_abs = 4000000000;

    for(int i=0; i<n; i++)
    {
        int left = i+1;
        int right = n-1;

        while(left < right)
        {
            long long sum = (long long)liq[i] + (long long)liq[left] + (long long)liq[right];
            long long cur_abs = abs(sum);
            
            if(cur_abs < min_abs)
            {
                ans.clear();
                ans.push_back(liq[i]);
                ans.push_back(liq[left]);
                ans.push_back(liq[right]);

                min_abs = cur_abs;
            }

            if(sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    for(int i=0; i<3; i++)
    {
        cout << ans[i] << " ";
    }
}