#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수강신청 부하 관리 시스템 도입
    // 조금이라도 빨리 버튼 누른 학생이 대기목록에 먼저 들어감
    // 이미 대기열에 들어간 상태에서 다시 버튼을 누르면 대기목록의 맨 뒤로 감
    // 수강신청 버튼 비활성화 되는 경우, 가장 앞 학생부터 자동으로 수강신청 완료

    unordered_map<string, int> waiting_id;
    int k, l;
    cin >> k >> l;

    for(int i=1; i<=l; i++)
    {
        string id;
        cin >> id;

        waiting_id[id] = i;
    }

    vector<pair<string,int>> sorted_id(waiting_id.begin(), waiting_id.end());
    sort(sorted_id.begin(), sorted_id.end(), cmp);

    k = min(k, (int)sorted_id.size());

    for(int i=0; i<k; i++)
    {
        cout << sorted_id[i].first << '\n';
    }
}