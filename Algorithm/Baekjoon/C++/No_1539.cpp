#include <iostream>
#include <set>

using namespace std;

long long answer = 0;

set<int> nodes;
int depth[250000];
bool has_left[250000];
bool has_right[250000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // p는 크기가 n인 배열
    // p의 값은 0~N-1이 중복없이 채워짐
    // p배열을 이용해서 이진검색트리를 만드는 방법이 있음

    int n;
    cin >> n;

    int root_value;
    cin >> root_value;

    depth[root_value] = 1;
    answer += 1;

    nodes.insert(root_value);

    for(int i=1; i<n; i++)
    {
        int value;
        cin >> value;

        auto next_it = nodes.lower_bound(value); // value보다 바로 큰 값

        if(next_it == nodes.end() || has_left[*next_it]) // value보다 큰 값이 없거나, 이미 왼쪽 자식이 존재하는 경우
        {
            auto prev_it = --next_it;   // value보다 바로 작은 값
            
            // cout << value << " is " << *prev_it << " 's right" << endl;

            nodes.insert(value);
            has_right[*prev_it] = true;
            depth[value] = depth[*prev_it] + 1;
            answer += depth[value];
        }
        else
        {
            // cout << value << " is " << *next_it << " 's left" << endl;

            nodes.insert(value);
            has_left[*next_it] = true;
            depth[value] = depth[*next_it] + 1;
            answer += depth[value];
        }
    }

    cout << answer;
}