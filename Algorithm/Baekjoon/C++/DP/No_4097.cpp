#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 창업한지 n일
// 매일 수익 기록 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while(true)
    {
        cin >> n;
        if(n == 0) break;

        vector<int> d(n+1, 0);          // i일에 반드시 끝나는 구간의 최고 수익
        int max_profit;                 // 현재 최고 수익
        int daily_profit;

        cin >> daily_profit;
        d[0] = daily_profit;
        max_profit = daily_profit;
        
        for(int i=1; i<n; i++)
        {
            // 2가지 상태 전이
            // 최고 수익 구간 연장, 새로운 구간 시작
            cin >> daily_profit;
            d[i] = max(d[i-1] + daily_profit, daily_profit);
            max_profit = max(max_profit, d[i]);
        }

        cout << max_profit << '\n';
    }
}