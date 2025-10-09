#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 가장 긴 엣지가 짧도록 출입구 - 산봉우리 경로 정하는 방법
// 출입구는 한 곳만, 방문 가능

// 인접 행렬 주어짐
// 인접 행렬 -> 인접 리스트로 변환이 필요할까?

// 모든 출입구 순회 -> 출입구마다 intensity 비교
// 다익스트라? i -> j까지 가는 intensity 최소가 되도록
// 출입구 순회하며 다익스트라 -> 산봉우리 순회하며 최소 intensity 갱신
// 최소 intensities 반환

// 출입구 / 산봉우리는 한 번만 갈 수 있다는 정보를 놓쳤다.
// -> 다익스트라 pq 원소 삽입 조건 추가

// 시간초과 이유 - 카카오 테크 블로그 해설
// 만약 모든 출입구에서 한 번씩 다익스트라 알고리즘을 따로 실행해 정답을 찾는다면 시간 초과가 발생하게 됩니다.
// 문제의 정답을 찾기 위해선 어느 출입구에서 출발하는지에 상관없이 intensity의 최솟값과 산봉우리의 번호만 알면 됩니다.
// 따라서 모든 출입구에서 다익스트라 알고리즘을 실행하는 대신, 한 번의 다익스트라에서 모든 출입구를 시작 정점으로 두고
// 알고리즘을 실행한다면 시간 초과를 피할 수 있습니다.

struct Node
{
    int num = 0;
    int type = 0;

    vector<Node*> adj;
};

void Print(int gate, vector<int>& vec)
{
    cout << gate << " gate intensities : " << endl;
    for (auto elem : vec)
    {
        cout << elem << " ";
    }
    cout << '\n';
}

vector<int> CalcIntensities(int start, const int& n, vector<Node>& nodes, vector<vector<int>>& adj_mat)
{
    vector<int> min_intensities = vector<int>(n + 1, 10000005);

    priority_queue<pair<int, Node*>> pq;
    min_intensities[start] = 0;
    pq.push({ 0, &nodes[start] });

    int temp_summit = 0;
    int temp_intensity = 10000005;

    while (!pq.empty())
    {
        int cur_intensity = pq.top().first;
        Node* cur_node = pq.top().second;
        pq.pop();

        if (min_intensities[cur_node->num] != cur_intensity) continue;

        for (Node* adj_node : cur_node->adj)
        {
            if (adj_mat[cur_node->num][adj_node->num] == -1) continue;

            int new_intensity = max(cur_intensity, adj_mat[cur_node->num][adj_node->num]);

            if (new_intensity < min_intensities[adj_node->num])
            {
                min_intensities[adj_node->num] = new_intensity;
                if (adj_node->type == 0) pq.push({ new_intensity, adj_node });

                if (adj_node->type == 2)
                {
                    if (new_intensity < temp_intensity)
                    {
                        temp_summit = adj_node->num;
                        temp_intensity = new_intensity;
                    }
                    else if (new_intensity == temp_intensity)
                    {
                        temp_summit = min(temp_summit, adj_node->num);
                    }
                }
            }
        }
    }

    vector<int> temp_answer;
    temp_answer.push_back(temp_summit);
    temp_answer.push_back(temp_intensity);

    return temp_answer;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<Node> nodes = vector<Node>(n + 1);
    vector<vector<int>> adj_mat = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; ++i) nodes[i].num = i;
    for (int gate : gates) nodes[gate].type = 1;
    for (int summit : summits) nodes[summit].type = 2;

    for (vector<int>& path : paths)
    {
        int i = path[0];
        int j = path[1];
        int w = path[2];

        adj_mat[i][j] = w;
        adj_mat[j][i] = w;

        nodes[i].adj.push_back(&nodes[j]);
        nodes[j].adj.push_back(&nodes[i]);
    }


    vector<int> answer;
    answer.push_back(0);
    answer.push_back(10000005);

    for (int gate : gates)
    {
        vector<int> temp_answer = CalcIntensities(gate, n, nodes, adj_mat);

        if (temp_answer[1] < answer[1]) answer = temp_answer;
        if (temp_answer[1] == answer[1] && temp_answer[0] < answer[0]) answer = temp_answer;
    }

    return answer;
}