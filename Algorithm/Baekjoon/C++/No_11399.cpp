#include <iostream>
#include <algorithm>

using namespace std;

int p[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ATM 1대, N명의 사람 줄
    // 사람은 1~N 번호, Pi 시간
    // 기다리는 시간의 합
    // 어떻게 하면 시간의 합을 최소화 할 수 있을까?
    // 뽑는데 조금 걸리는 사람을 앞에 배치하자.

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> p[i];
    }

    sort(p, p + n);

    int time_sum = 0;

    for(int i=0; i<n; i++)
    {
        time_sum += (n - i) * p[i];
    }

    cout << time_sum;
}