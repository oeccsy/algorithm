#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> seq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 길이가 N인 수열
    // 수열의 합 구하려고 함
    // 이때 수열의 두 수를 묶으려고 한다.
    // 위치와 관계없이 다른 위치의 두 수를 묶음
    // 묶으면, 수열의 합을 구할 때 서로 곱한 후 더한다.

    // 0, 1만 아니면 무조건 묶는게 이득이다.
    // 음수는 반드시 가장 작은 수 부터 음수와 묶는다.

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        
        seq.push_back(num);
    }

    sort(seq.begin(), seq.end());

    int max = 0;
    auto iter = seq.begin();
    
    while(iter < seq.end() && *iter < 0)
    {
        if(iter + 1 < seq.end() && (*(iter + 1)) <= 0)
        {
            max += (*iter) * (*(iter + 1));
            iter++;
            iter++;
        }
        else
        {
            max += *iter;
            iter++;
        }
    }

    iter = seq.end() - 1;

    while(iter >= seq.begin() && *iter >= 1)
    {
        if(iter - 1 >= seq.begin() && (*(iter - 1)) > 1)
        {
            max += (*iter) * (*(iter - 1));
            iter--;
            iter--;
        }
        else
        {
            max += *iter;
            iter--;
        }
    }

    cout << max;
}