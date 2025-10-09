#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 가장 긴 엣지가 짧도록 출입구 - 산봉우리 경로 정하는 방법
// 출입구는 한 곳만, 방문 가능

// 출입구 / 산봉우리는 한 번만 갈 수 있다는 정보를 놓쳤다.

// 엣지 정렬
// 엣지 intensity 낮은 것부터 연결
// 출입구 / 산봉우리 동시에 연결된 시점이 최소 아닐까

// 엣지를 정렬된 상태로 추가하는 경우 연결된 컴포넌트가 아닐 수 있음
// Union-Find 알고리즘 수행
// gate_connected, summit_connected 둘다 만족시 현재 intensity 컨펌
// 같은 intensity 나올때까지 지속

// 출입구 / 산봉우리는 한 번만 갈 수 있다는 조건을 반영하기 어려웠음
// 모든 출발점, 산봉우리는 사실상 트리와 트리를 이어주는 대상은 아니다.
// 그냥 그 트리에 정보만 추가해야겠다

int Find(int i, vector<int>& parent)
{
    if (parent[i] != i)
    {
        parent[i] = Find(parent[i], parent);
    }

    return parent[i];
}

void Union(int i, int j, vector<int>& parent, vector<bool>& gate_connected, vector<int>& summit_connected)
{
    int root_i = Find(i, parent);
    int root_j = Find(j, parent);

    if (root_i != root_j)
    {
        parent[root_j] = root_i;
        gate_connected[root_i] = gate_connected[root_i] || gate_connected[root_j];
        summit_connected[root_i] = min(summit_connected[root_i], summit_connected[root_j]);
    }
}


bool Compare(const vector<int>& a, const vector<int>& b)
{
    return a[2] < b[2];
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<int> type_info = vector<int>(n + 1, 0);
    vector<int> parent = vector<int>(n + 1, 0);
    vector<bool> gate_connected = vector<bool>(n + 1, false);
    vector<int> summit_connected = vector<int>(n + 1, 50005);

    for (int gate : gates) type_info[gate] = 1;
    for (int summit : summits) type_info[summit] = 2;
    for (int i = 1; i <= n; ++i) parent[i] = i;

    sort(paths.begin(), paths.end(), Compare);

    int answer_summit = 50000;
    int answer_intensity = 0;

    for (vector<int>& path : paths)
    {
        int i = path[0];
        int j = path[1];
        int w = path[2];

        int root_i = Find(i, parent);
        int root_j = Find(j, parent);

        if (answer_intensity > 0 && answer_intensity != w) break;

        if (type_info[i] == 1 || type_info[j] == 1)
        {
            gate_connected[root_i] = true;
            gate_connected[root_j] = true;
        }

        if (type_info[i] == 2)
        {
            summit_connected[root_i] = min(summit_connected[root_i], i);
            summit_connected[root_j] = min(summit_connected[root_j], i);
        }

        if (type_info[j] == 2)
        {
            summit_connected[root_i] = min(summit_connected[root_i], j);
            summit_connected[root_j] = min(summit_connected[root_j], j);
        }

        if (type_info[i] == 0 && type_info[j] == 0)
        {
            Union(i, j, parent, gate_connected, summit_connected);
        }

        bool is_i_valid_answer = (gate_connected[root_i] && summit_connected[root_i] <= 50000);
        bool is_j_valid_answer = (gate_connected[root_j] && summit_connected[root_j] <= 50000);

        if (is_i_valid_answer)
        {
            answer_summit = min(answer_summit, summit_connected[root_i]);
            answer_intensity = w;
        }

        if (is_j_valid_answer)
        {
            answer_summit = min(answer_summit, summit_connected[root_j]);
            answer_intensity = w;
        }
    }

    vector<int> answer;
    answer.push_back(answer_summit);
    answer.push_back(answer_intensity);

    return answer;
}