#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 배열의 일부를 부 배열이라 말한다.
    // 길이가 n, m인 두 배열 A, B가 주어졌을 때
    // A의 부배열의 합에 B의 부배열의 합이 T가 되는 부 배열의 조합 개수

    int t, n, m;
    cin >> t;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }

    cin >> m;

    for(int i=0; i<m; i++)
    {
        int input;
        cin >> input;
        b.push_back(input);
    }

    long long count = 0;
    vector<int> sum_a;
    vector<int> sum_b;

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += a[j];
            sum_a.push_back(sum);
        }
    }

    for(int i=0; i<m; i++)
    {
        int sum = 0;
        for(int j=i; j<m; j++)
        {
            sum += b[j];
            sum_b.push_back(sum);
        }
    }

    sort(sum_b.begin(), sum_b.end());

    for(int sum : sum_a)
    {
        count += upper_bound(sum_b.begin(), sum_b.end(), t-sum) - lower_bound(sum_b.begin(), sum_b.end(), t-sum);
    }

    cout << count;
}