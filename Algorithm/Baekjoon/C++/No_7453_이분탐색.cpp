#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> a;
vector<long long> b;
vector<long long> c;
vector<long long> d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int a_input, b_input, c_input, d_input;
        cin >> a_input >> b_input >> c_input >> d_input;

        a.push_back(a_input);
        b.push_back(b_input);
        c.push_back(c_input);
        d.push_back(d_input);
    }

    vector<long long> sum_ab;
    vector<long long> sum_cd;

    long long count = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum_ab.push_back(a[i] + b[j]);
            sum_cd.push_back(c[i] + d[j]);
        }
    }

    sort(sum_cd.begin(), sum_cd.end());

    for(int i=0; i<n*n; i++)
    {
        count += upper_bound(sum_cd.begin(), sum_cd.end(), -sum_ab[i]) - lower_bound(sum_cd.begin(), sum_cd.end(), -sum_ab[i]);
    }

    cout << count;
}