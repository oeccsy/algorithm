#include <iostream>
#include <unordered_map>

using namespace std;

long long n, p, q;
unordered_map<long long, long long> a;

int calc_a(long long i)
{
    if(a.find(i/p) == a.end()) calc_a(i/p);
    if(a.find(i/q) == a.end()) calc_a(i/q);

    a[i] = a[i/p] + a[i/q];
    
    return a[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 무한 수열 A는 다음과 같다.
    // A(0) = 1
    // A(i) = A(i/P) + A(i/Q)

    // N의 최대 값 1조 -> 배열로 대응 불가, 1부터 dp 수행하면 시간초과
    // n 부터 -> n/p , i/p ... 수행

    cin >> n >> p >> q;
    a[0] = 1;

    if(a.find(n) == a.end()) calc_a(n);

    cout << a[n];   
}