#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Jewel 
{
    int m;
    int v;
};

Jewel jewels[300005];
multiset<int> bags;

bool cmp(const Jewel& a, const Jewel& b)
{
    if(a.v != b.v)
    {
        return a.v > b.v;
    }
    else
    {
        return a.m < b.m;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 보석 n개
    // 보석은 무게 mi, 가격 vi를 가지고 있다.
    // 가방을 k개 가지고 있고, 가방에 담을 수 있는 최대 무게 ci
    // 가방에는 최대 한 개의 보석만 넣을 수 있다.
    // 훔칠 수 있는 최대 보석의 가격
    // 비싼거부터 하나씩 넣을 수 있는 가장 작은 가방에 넣어보기

    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++)
    {
        cin >> jewels[i].m >> jewels[i].v;
    }

    for(int i=0; i<k; i++)
    {
        int c;
        cin >> c;
        bags.insert(c);
    }

    sort(jewels, jewels + n, cmp);

    long long answer = 0;

    for(int i=0; i<n; i++)
    {
        // lower bound를 이용해서, "넣을 수 있는 가장 작은 가방" 을 찾기
        int cur_m = jewels[i].m;
        int cur_v = jewels[i].v;

        auto it = bags.lower_bound(cur_m);
        if(it == bags.end()) continue;

        answer += cur_v;
        bags.erase(it);
    }

    cout << answer;
}