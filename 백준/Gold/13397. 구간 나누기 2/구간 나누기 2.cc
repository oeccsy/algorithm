#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;

bool is_possible(vector<int>& vec, int max_score, int max_sec_count)
{
    int sec_max = vec[0];
    int sec_min = vec[0];
    int sec_count = 1;

    for(int i=1; i<vec.size(); i++)
    {
        sec_max = max(sec_max, vec[i]);
        sec_min = min(sec_min, vec[i]);

        if(sec_max - sec_min > max_score)
        {
            sec_count++;
            sec_max = vec[i];
            sec_min = vec[i];
        }
    }

    return sec_count <= max_sec_count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        num.push_back(input);
    }

    int pred_min = 0;
    int pred_max = *max_element(num.begin(), num.end());
    int result = pred_max;
    
    while(pred_min <= pred_max)
    {
        int check_target = (pred_min + pred_max) / 2;

        if(is_possible(num, check_target, m))
        {
            result = min(result, check_target);
            pred_max = check_target - 1;
        }
        else
        {
            pred_min = check_target + 1;
        }
    }

    cout << result;
    // 1 5 4 6 2 1 3 7
    // 이 있을 때,
    // M개의 이하의 구간으로 나누어서
    // 각 구간의 최댓값을 최소로 하려고 한다.
    // 이때 만들 수 있는 각 구간의 최댓값의 최소는?

    // max_sec_count이내에
    // 각 구간의 최댓값을 check_target로 할 수 있는가?

    // decision(arr, max_score, max_sec_count) = ?
}