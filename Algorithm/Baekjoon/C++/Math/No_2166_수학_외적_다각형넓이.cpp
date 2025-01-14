#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 2차원 평면상에 N개의 점으로 이루어진 다각형.
    // 이 다각형의 면적 구하기
    
    // 두 점을 가리키는 vec의 외적 -> |v1||v2|sin(8)
    // -> 두 벡터가 이루는 삼각형 * 2 (==평행사변형)
    
    // 성분을 통해 외적 연산 수행 (기준점을 원점으로 한 신발끈)
    // -> 1/2 | (x[i] * y[i+1] ... + x[n-1] * y[0]) - (x[i+1] * y[i] ... + x[0] * y[n-1]) |
    
    // 기준점을 x[0], y[0]으로 하면,
    // x[n-1] * y[0] -> (x[n-1] - x[0]) * (y[0] - y[0]) = 0
    // x[0] * y[n-1] -> (x[0] - x[0]) * (y[n-1] - y[0]) = 0
    // 따라서 간결해진 연산 수행 가능

    int n;
    cin >> n;

    vector<long long> x;
    vector<long long> y;

    for(int i=0; i<n; i++)
    {
        long long input_x, input_y;
        cin >> input_x >> input_y;
        x.push_back(input_x);
        y.push_back(input_y);
    }

    long long sum = 0;

    for(int i=0; i<n-1; i++)
    {
        sum += (x[i] - x[0]) * (y[i+1] - y[0]) - (x[i+1] - x[0]) * (y[i] - y[0]);
    }

    double area = abs(sum) / 2.0;
    cout << fixed;
    cout.precision(1);
    cout << area;
}