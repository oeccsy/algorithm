#include <iostream>
#include <algorithm>

using namespace std;

int d[100001];
int num[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> num[i];
    }

    int answer = num[1];
    d[1] = num[1];
    
    for(int i=2; i<=n; i++)
    {
        d[i] = max(num[i], d[i-1] + num[i]);
        if(d[i] > answer) answer = d[i];
    }

    cout << answer;
}