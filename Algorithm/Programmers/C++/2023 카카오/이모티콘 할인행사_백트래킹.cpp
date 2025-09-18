#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이모티콘 서비스 가입자 최대한 - 1순위
// 이모티콘 판매액 최대한 - 2순위

// 행사
// n명의 카카오톡 사용자, m개 할인 판매
// 할인율 10%~40%중 하나

// 일정 비율 이상 할인 모두 구매
// 구매 비용 합이 일정 가격 이상 -> 이모티콘 플러스 가입

// 구매기준 배열 users
// 이모티콘 m개 정가 emoticons
// 행사 목적을 최대한으로 달성했을 때 {가입 수, 매출액} 반환

// users의 길이 : 100
// emoticons의 길이 7 -> 백트래킹?

vector<int> event_types;
vector<int> events;

int max_subs = 0;
int max_sell = 0;

void solve(int depth, vector<vector<int>>& users, vector<int>& emoticons)
{
    if (depth >= emoticons.size())
    {
        vector<int> costs;

        for (int i = 0; i < emoticons.size(); ++i)
        {
            int emoticon = emoticons[i];
            int event = events[i];

            int cost = emoticon * (100 - event) / 100;
            costs.push_back(cost);
        }

        int temp_subs = 0;
        int temp_sell = 0;

        for (auto user : users)
        {
            int sum = 0;

            for (int i = 0; i < emoticons.size(); ++i)
            {
                if (user[0] <= events[i]) sum += costs[i];
            }

            if (user[1] <= sum)
            {
                temp_subs += 1;
            }
            else
            {
                temp_sell += sum;
            }
        }

        if (max_subs < temp_subs)
        {
            max_subs = temp_subs;
            max_sell = temp_sell;
        }
        else if (max_subs == temp_subs)
        {
            max_sell = max(max_sell, temp_sell);
        }

        return;
    }

    for (int i = 0; i < event_types.size(); ++i)
    {
        events.push_back(event_types[i]);

        solve(depth + 1, users, emoticons);

        events.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    event_types.push_back(10);
    event_types.push_back(20);
    event_types.push_back(30);
    event_types.push_back(40);

    solve(0, users, emoticons);

    vector<int> answer;
    answer.push_back(max_subs);
    answer.push_back(max_sell);
    return answer;
}