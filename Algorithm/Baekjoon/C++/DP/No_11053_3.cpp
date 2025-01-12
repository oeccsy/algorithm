#include <iostream>
#include <algorithm>

using namespace std;

int a[1005];
int d[1005];    // i번째 수를 포함했을 때 가능한 최대 길이

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수열 A의 크기 N
    // Ai 주어짐

    int answer = 0;

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        d[i] = 1;

        for(int j=0; j<i; j++)
        {
            if(a[j] < a[i]) // i번째 수를 추가 가능 (뒷 순서 수는 고려 X, 추후에 다시 고려됨) 
            {
                d[i] = max(d[j] + 1, d[i]);
            }
        }
    }

    cout << *max_element(d, d+n);
}