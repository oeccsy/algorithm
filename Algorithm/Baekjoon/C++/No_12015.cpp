#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_len = 0;
vector<int> temp;
// Temp의 길이는 항상 최대의 LIS의 길이를 유지하면서,
// 비교는 가장 마지막 원소로 수행하여 기존의 LIS에 길이 추가를 대비하였고,
// 마지막이 아닌 기존의 원소는 최적의 LIS 원소로 교체하여 새로운 LIS를 대비하고 있다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 

    int a0;
    cin >> a0;
    temp.push_back(a0);
    max_len = 1;

    for(int i=1; i<n; i++)
    {
        int ai;
        cin >> ai;

        if(temp.back() < ai) // 추가 가능
        {
            temp.push_back(ai);
            max_len++;
        }
        else
        {
            auto iter = lower_bound(temp.begin(), temp.end(), ai);
            *iter = ai;
        }
    }

    cout << max_len;
}