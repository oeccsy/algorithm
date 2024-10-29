#include <iostream>
#include <set>

using namespace std;
set<int> hot_place;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N개의 구역 원형 배치
    // 1구역에서부터 시계방향으로 진행 (1~N)

    // 1 i : i번 구역이 명소가 아니었다면 명소로 지정, 명소면 풀림
    // 2 x : 시계방향으로 x만큼 이동
    // 3 : 명소에 도달하기 위해 시계방향으로 몇칸 움직여야 하는지 출력, 명소 없으면 -1 출력

    int n, q;
    cin >> n >> q;

    for(int i=1; i<=n; i++)
    {
        int is_hot_place;
        cin >> is_hot_place;

        if(is_hot_place) hot_place.insert(i);
    }

    int cur_place = 1;

    for(int i=0; i<q; i++)
    {
        int cmd, arg;
        cin >> cmd;

        switch(cmd)
        {
            case 1:
                cin >> arg;

                if(hot_place.find(arg) == hot_place.end())
                    hot_place.insert(arg);
                else
                    hot_place.erase(arg);
                break;
            case 2:
                cin >> arg;

                cur_place = (cur_place + arg + (n - 1)) % n + 1;
                break;
            case 3:
                int next_hot_place;
                auto it = hot_place.lower_bound(cur_place);
                if(it == hot_place.end()) it = hot_place.lower_bound(0);
                
                if(it == hot_place.end())
                {
                    cout << -1 << '\n';
                }
                else
                {
                    next_hot_place = *it;
                    cout << (next_hot_place - cur_place + n) % n << '\n';
                }
                break;
        }    
    }
}