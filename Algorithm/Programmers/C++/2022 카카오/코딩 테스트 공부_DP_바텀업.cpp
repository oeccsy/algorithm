#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 알고력, 코딩력 0 이상의 정수
// 알고력 코딩력 모두 만족해야 풀 수 있음

// 알고력/코딩력 높이기 위해 1당 1시간 공부하는 방법
// 올라가는 알고력/코딩력과 푸는데 걸리는 시간이 정해져있는 문제를 푸는 방법

// 모든 문제를 풀 수 있는 알고력/코딩력을 얻는 최단 시간
// 모든 문제를 풀 필요는 없음

// dp?
// d[i][j] 가 i알고력, j코딩력이라고 할 때 해당 알고/코딩력에 도달하는 가장 짧은 시간

int d[151][151];

// 탑다운 dp -> 스택 오버플로
// 바텀업 방식으로 가능할까?
// 목표 alp/cop보다 초기 alp/cop가 높은 경우 반복문 순환(alp ~ goal_alp)과 반환할 원소(d[goal_alp][goal_cop)에 대응하는 방법을 찾는게 어려웠음

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int goal_alp = alp;
    int goal_cop = cop;

    for (vector<int>& problem : problems)
    {
        goal_alp = max(goal_alp, problem[0]);
        goal_cop = max(goal_cop, problem[1]);
    }

    vector<int> alp_up_case = { 0, 0, 1, 0, 1 };
    vector<int> cop_up_case = { 0, 0, 0, 1, 1 };
    problems.push_back(alp_up_case);
    problems.push_back(cop_up_case);

    for (int i = alp; i <= goal_alp; ++i)
    {
        for (int j = cop; j <= goal_cop; ++j)
        {
            d[i][j] = 100000;
        }
    }

    d[alp][cop] = 0;

    for (int i = alp; i <= goal_alp; ++i)
    {
        for (int j = cop; j <= goal_cop; ++j)
        {
            for (vector<int>& problem : problems)
            {
                int alp_req = problem[0];
                int cop_req = problem[1];
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost = problem[4];

                // 문제를 풀 수 없는 경우
                if (i < alp_req) continue;
                if (j < cop_req) continue;

                int next_alp = (goal_alp <= i + alp_rwd) ? goal_alp : i + alp_rwd;
                int next_cop = (goal_cop <= j + cop_rwd) ? goal_cop : j + cop_rwd;

                d[next_alp][next_cop] = min(d[next_alp][next_cop], d[i][j] + cost);
            }
        }
    }

    return d[goal_alp][goal_cop];
}