#include <string>
#include <vector>

using namespace std;

// 목표 : nlog n

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    // 끝에있는 집부터 배달 시작
    // 최대한 싣고 감
    // 돌아오면서 최대한 회수

    long long answer = 0;

    while (!deliveries.empty() || !pickups.empty())
    {
        // 가지 않아도 되는 집 제거
        while (!deliveries.empty() && deliveries.back() == 0) deliveries.pop_back();
        while (!pickups.empty() && pickups.back() == 0) pickups.pop_back();

        // 이동 거리 계산
        int deliver_dist = deliveries.size();
        int pickups_dist = pickups.size();
        answer += max(deliver_dist, pickups_dist) * 2;

        // 배달
        int remain_deliver = cap;
        int remain_pickup = cap;

        while (!deliveries.empty() && remain_deliver > 0)
        {
            int cur_deliver = min(deliveries.back(), remain_deliver);
            remain_deliver -= cur_deliver;
            deliveries.back() -= cur_deliver;

            if (deliveries.back() == 0) deliveries.pop_back();
        }

        while (!pickups.empty() && remain_pickup > 0)
        {
            int cur_pickup = min(pickups.back(), remain_pickup);
            pickups.back() -= cur_pickup;
            remain_pickup -= cur_pickup;

            if (pickups.back() == 0) pickups.pop_back();
        }
    }

    return answer;
}