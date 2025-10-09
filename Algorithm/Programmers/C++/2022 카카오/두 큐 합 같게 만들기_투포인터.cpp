#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 길이 같은 두 큐
// 하나 pop -> 다른 큐 push
// 목표 : 각 큐의 원소 합 동일
// 일열로된 배열이라고 봐도 무방
// 왜냐하면 순서가 절대로 섞일 수 없음
// 투포인터
// 투포인터로 합이 goal인 두 지점을 가리킬 수 있다면 ok 아니면 실패
// 처음에 queue1[0], queue2[0]을 가리킴 [st, en)

int solution(vector<int> queue1, vector<int> queue2)
{
    long long sum_1 = 0;
    long long sum_2 = 0;
    long long goal = 0;

    for (int i = 0; i < queue1.size(); ++i)
    {
        sum_1 += queue1[i];
        sum_2 += queue2[i];
    }

    if ((sum_1 + sum_2) % 2 == 1) return -1;
    goal = (sum_1 + sum_2) / 2;

    long long cur_sum = sum_1;
    int st = 0;
    int en = 0;
    int answer = 0;

    vector<int>* st_vec = &queue1;
    vector<int>* en_vec = &queue2;

    while (true)
    {
        if (cur_sum == goal) return answer;

        if (cur_sum < goal)
        {
            if (en < en_vec->size())
            {
                cur_sum += (*en_vec)[en];
                ++en;
                ++answer;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (st < st_vec->size())
            {
                cur_sum -= (*st_vec)[st];
                ++st;
                ++answer;
            }
            else
            {
                if (st_vec == &queue1)
                {
                    st_vec = &queue2;
                    st = 0;
                }
                else
                {
                    return -1;
                }
            }
        }
    }

    return -1;
}