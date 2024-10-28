#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Q라는 이중 우선순위큐 존재
    // Q에 적용될 연산 주어질 때, 처리한 후 Q에 저장된 데이터 중 최대/최솟값 출력

    // t 개의 테스트 데이터
    // Q에 적용할 연산 수 k
    // I insert
    // D delete 1 max, -1 min
    // 비어있는 경우 continue;

    int t;
    cin >> t;

    for(int i=0; i<t; i++)
    {
        multiset<int> q;

        int k;
        cin >> k;

        for(int j=0; j<k; j++)
        {
            char cmd;
            int arg;
            cin >> cmd >> arg;
            
            if(cmd == 'I')
            {
                q.insert(arg);
            }
            else
            {
                if(q.empty()) continue;

                if(arg == 1)
                {
                    q.erase(--q.end());
                }
                else
                {
                    q.erase(q.begin());
                }
            }
        }

        if(q.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            cout << *(--q.end()) << ' ' << *q.begin() << '\n';
        }
    }
}