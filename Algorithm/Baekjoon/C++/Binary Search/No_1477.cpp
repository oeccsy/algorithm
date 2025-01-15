#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m ,l;
vector<int> highway;

bool is_possible(int max_dist)
{
    int add_count = 0;
    int prev_pos = 0;

    for(int cur_pos : highway)
    {
        int cur_dist = cur_pos - prev_pos;
 
        while(cur_dist > max_dist)
        {
            add_count++;
            if(add_count > m) return false;

            prev_pos = prev_pos + max_dist;
            cur_dist = cur_pos - prev_pos;
        }

        prev_pos = cur_pos;
    }

    return add_count <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 유료 고속도로
    // 휴개소 n개
    // 시작점부터의 위치 주어짐
    // 휴게소 m개를 반드시 더 세우려고 함.
    // 휴게소 사이 길이의 최댓값의 최솟값은?

    // m개를 지었을 때, 최댓값은 target 이하가 될 수 있는가?

    cin >> n >> m >> l;
    highway = vector<int>(n);

    for(int i=0; i<n; i++)
    {
        cin >> highway[i];
    }
    
    highway.push_back(0);
    highway.push_back(l);
    sort(highway.begin(), highway.end());

    int min = l;

    int left = 0;
    int right = l;
    
    while(left <= right)
    {
        int check_target = (left + right) / 2;

        if(is_possible(check_target))
        {
            min = check_target;
            right = check_target - 1;
        }
        else
        {
            left = check_target + 1;
        }
    }

    cout << min;
}