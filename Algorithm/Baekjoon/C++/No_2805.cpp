#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> trees;

bool is_possible(int h, int m)
{
    long long sum = 0;

    for(int tree : trees)
    {
        if(tree - h > 0) sum += tree - h;
    }

    return sum >= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 나무 m 미터 필요
    // 나무 한 줄 벌목 [20 15 10 17]
    
    // 나무 절단 방법
    // 절단기에 높이 h를 지정한다.
    // 톱날이 땅으로부터 h미터 위로 올라간다.
    // h미터 위의 잘린 부분을 가지고 간다.

    // 필요한 만큼만 가져가려고 한다.
    // 적어도 m미터의 나무를 집에 가져가기 위해 절단할 수 있는 높이의 최댓값

    // 결정문제로 바꿔보자
    // h미터를 자른다고 했을 때, 적어도 m미터를 가져갔는가?
    // 그리고 가져갔을때, 최대의 h미터를 기록

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        int tree;
        cin >> tree;
        trees.push_back(tree);
    }

    int pred_max = *max_element(trees.begin(), trees.end());
    int pred_min = 0;
    int answer = 0;

    while(pred_min <= pred_max)
    {
        int target_h = (pred_max + pred_min) / 2;

        if(is_possible(target_h, m))
        {
            answer = max(answer, target_h);
            pred_min = target_h + 1;
        }
        else
        {
            pred_max = target_h - 1;
        }
    }

    cout << answer;
}